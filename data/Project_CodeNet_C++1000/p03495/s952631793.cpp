#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
typedef long long int ll;
 
int main()
{
 int N,K;
 int a[200002]={};
 scanf("%d %d",&N,&K);
 for(int i=0;i<N;i++)
 {
	int b; scanf("%d",&b);
	a[b]++;
 }
 sort(a,a+200001,greater<>());
 int ans=0;
 for(int i=K;i<=200001;i++)
 {
	ans+=a[i];
 }
 printf("%d",ans);
} 