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
const ll cs=1000000000;
//15
bool z[1000]={};

int main()
{
 int N,Z,W,a[2002];
 int x[2002]={},y[2002]={}; //x,yにr枚取られた状態で回ってきた時のスコア
 scanf("%d %d %d",&N,&Z,&W);
 a[0]=W;
 for(int i=1;i<=N;i++)
 {
	scanf("%d",&a[i]);
 }
 x[N-1]=y[N-1]=abs(a[N-1]-a[N]);
 for(int i=N-1;i>=0;i--)
 {
	//i枚とられた状態でxに回る→yはa[i]を持っている
	//ここでxが取りうるスコアは全部取るa[i]-a[N]と「j枚とられた状態でyに回る」=y[j](j>i) これの中で一番大きいものがx[i]
	int bs=abs(a[i]-a[N]);
	for(int j=i+1;j<N;j++)
	{
		bs=max(bs,y[j]);
	}
	x[i]=bs;
	
	//i枚とられた状態でyに回る→xはa[i]を持っている
	//ここでyが取りうるスコアは全部取るa[i]-a[N]と「j枚とられた状態でyに回る」=x[j](j>i) これの中で一番小さいものがy[i]
	bs=abs(a[i]-a[N]);
	for(int j=i+1;j<N;j++)
	{
		bs=min(bs,x[j]);
	}
	y[i]=bs;
 }
 printf("%d\n",x[0]);
}