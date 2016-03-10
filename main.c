//
//  main.c
//  二叉树
//
//  Created by 何灏 on 15/11/15.
//  Copyright © 2015年 何灏. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data;
    struct node *l,*r;
};
int nu=0;
struct node *build (struct node *t)
{
    char x;
   
    x=getchar();
    if (x==',')
        t=NULL;
    else
    {
        t=(struct node *)malloc(sizeof (struct node ));
        t->data=x;
        t->l=build(t->l);
        t->r=build(t->r);
    }
    return t;
}
void mid (struct node *t)
{
    if (t!=NULL)
    {
        mid(t->l);
        printf ("%c",t->data);
        mid(t->r);
    }
}
void last (struct node *t)
{
    if (t!=NULL)
    {
        last(t->l);
        last (t->r);
        printf ("%c",t->data);
    }
}
void num (struct node *t)
{
    if (t!=NULL)
    {
        if (t->l==NULL && t->r == NULL)
            nu++;
        else
        {
            num (t->l);
            num (t->r);
        }
    }
}
int depth (struct node *t)
{
    int a=0,b=0;
    if (t!=NULL)
    {
        a=depth(t->l);
        b=depth(t->r);
        if (a>b)
            return a+1;
        else
            return b+1;
    }
    return 0;
    
}
int main ()
{
    int de;
    struct node *tree= NULL;//创建新的结构体用来存储生成的二叉树
    
    tree=build(tree);//生成二叉树
    mid (tree);//中序
    printf ("\n");
    last (tree);//后序
    printf ("\n");
    num (tree);//查找叶子的个数
    printf ("%d\n",nu);
    de=depth(tree);//求深度
    printf ("%d\n",de);
    return 0;
}