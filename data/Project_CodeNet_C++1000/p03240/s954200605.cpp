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
 int N;
 int x[100],y[100],h[100];
 scanf("%d",&N);
 int z;
 for(int i=0;i<N;i++)
 {
	scanf("%d %d %d",&x[i],&y[i],&h[i]);
	if(h[i]!=0){z=i;}
 }
 int ans=-1;
 int anx=-1,any=-1;
 for(int i=0;i<=100;i++)
 {
	for(int j=0;j<=100;j++)
	{
		int flg=1;
		int pt=h[z]+abs(i-x[z])+abs(j-y[z]);
		for(int k=0;k<N;k++)
		{
			if(max(pt-abs(i-x[k])-abs(j-y[k]),0)!=h[k]){flg=-1;}
		}
		if(flg==1&&pt>=0){anx=i; any=j; ans=pt;}
	}
 }
 printf("%d %d %d",anx,any,ans);
} 