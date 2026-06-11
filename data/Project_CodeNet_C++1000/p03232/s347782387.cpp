
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

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define swap(p,q) r=(p);(p)=(q);(q)=r
#define INF 1000000000000//10^12
#define INFINT 2000000001//2*10^9+1
#define MOD 1000000007

using namespace std;

ll int mod_inverse(int a,int M){
	int x=M-2;
	ll int temp=a;
	ll int ret=1;
	//a^(MOD-1)==1(mod MOD)を利用
	//a^-1==a^(MOD-2) (mod MOD)を繰り返し二乗法で求める

	while(x!=0){
		if(x%2==1){
			ret=(ret*temp)%M;
		}
		temp=(temp*temp)%M;
		x=x/2;
	}
	return ret;
}


int main(void)
{
	//変数の宣言
	int n;
	static int a[100010];
	static ll int dp[100010];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	ll int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;



	//データの読み込み


	scanf("%d",&n);
//	scanf_s("%d",&n);


	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
//		scanf_s("%d",&a[i]);
	}

	
	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	dp[0]=0;
	for(i=1;i<=n;i++){
		dp[i]=(dp[i-1]+mod_inverse(i,MOD))%MOD;
	}

	for(i=0;i<n;i++){
		ans=(ans+a[i]*(dp[n-i]+dp[i+1]-1))%MOD;
	}

	for(i=1;i<=n;i++){
		ans=ans*i%MOD;
	}

/*	for(i=0;i<=n;i++){
		printf("dp[%d]=%d\n",i,dp[i]);
	}*/

	//	printf("計算部分終了\n");

	//出力

	printf("%lld",ans);

	//	printf("結果の出力終了\n");


	return 0;
}

