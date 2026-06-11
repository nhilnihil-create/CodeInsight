#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<math.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int N,M;
int x,l;
pair<int,int> itv[100005];

int main()
{
 scanf("%d %d",&N,&M);
 for(int i=0;i<M;i++)
 {
	scanf("%d %d",&itv[i].second,&itv[i].first); //secondがa firstがbであることに注意
 }
 //bでソートして(b-1)-(b)橋を壊す
 sort(itv,itv+M);
int ans=0,brk=-1;
 for(int i=0;i<M;i++)
 {
	if(brk<itv[i].second){brk=itv[i].first-1; ans++;}
 }
 printf("%d",ans);

}