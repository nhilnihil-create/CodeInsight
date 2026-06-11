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
	int n,a,b,c;
	static ll conbi[100010]; 
	static ll ruijouA[100010];
	static ll ruijouB[100010];
	ll modAB;

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	ll int ans=0;
	int count=0;
	ll int temp=0;
	ll int temp1=0;
	ll int temp2=0;
	int temp3=0;
	int max=0;
	int min=INFINT;
	int len=0;
	ll int sum=0;
	int ok=0;
	int ng=0;
	char dummy;
	char stemp[11];
	ll antisum;

	//データの読み込み


	scanf("%d",&n);
//	scanf_s("%d",&n);

//	scanf("%s",&s);
//	scanf_s("%s",&s,5);


/*	for(i=0;i<n;i++){
//		scanf("%d",&s[i]);
		scanf_s("%d",&s[i]);
	}*/


/*	for(i=0;i<m;i++){
//		scanf("%d",&p[i]);
		scanf_s("%d",&p[i]);
	}*/

	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	//	printf("計算部分終了\n");

	//出力
	printf("%d",(n-2)*180);

//	printf("\n mod_inverse(93/16)=%lld",5*mod_inverse(8,MOD)%MOD);
	//	printf("結果の出力終了\n");

	return 0;
}

