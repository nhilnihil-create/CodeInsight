//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <bitset>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000000000//10^18
#define INFINT 2000000001//2*10^9+1
#define MOD 1000000007
#define MODANOTHER 998244353
#define PI acos(-1)

using namespace std;

int compare_ll(const void *a, const void *b)
{
	ll *A = (ll *)a;
	ll *B = (ll *)b;
	if (*A < *B) return 1;
	if (*A > *B) return -1;//昇順と降順あってる？
	return 0;
}

int main(void)
{
	//変数の宣言
	int n;
	int t[110];
	int v[110];
	double s[40010];
	int ruiseki[110];
	int memo[110];


	//よく使う変数
	int i,j,k,l;
	int flag=0;
	double ans=0;
	int count=0;
	double temp=0;
	int temp1=0;
	int temp2=0;
	int max=0;
	int min=INFINT;
	int len=0;
	int sum=0;
	int ok=0;
	int ng=0;
	int dummy;



	//データの読み込み


	scanf("%d",&n);
//	scanf_s("%d",&n);


	for(i=0;i<n;i++){
		scanf("%d",&t[i]);
//		scanf_s("%d",&t[i]);
	}

	v[0]=0;
	for(i=1;i<=n;i++){
		scanf("%d",&v[i]);
//		scanf_s("%d",&v[i]);
	}
	v[n+1]=0;
	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	ruiseki[0]=0;
	for(i=1;i<=n;i++){
		ruiseki[i]=ruiseki[i-1]+t[i-1];
	}


	for(i=0;i<=n;i++){
		for(j=0;j<=ruiseki[n]*2;j++){
			temp=j;
			if(i==0){
				s[j]=min(temp/2,ruiseki[n]-temp/2);
			}else if(temp/2<ruiseki[i-1]){
				s[j]=min(s[j],v[i]+ruiseki[i-1]-temp/2);
			}else if(temp/2>ruiseki[i]){
				s[j]=min(s[j],v[i]+temp/2-ruiseki[i]);
			}else{
				s[j]=min(s[j],v[i]);
			}
		}
	}

	ans=0;
	for(i=0;i<ruiseki[n]*2;i++){
		ans=ans+s[i]+s[i+1];
	}


	//	printf("計算部分終了\n");

	//出力
	printf("%lf",ans/4);

/*	for(i=0;i<=ruiseki[n]*2;i++){
		printf("i=%d,s[i]=%lf\n",i,s[i]);
	}*/

	//	printf("結果の出力終了\n");

	return 0;
}

