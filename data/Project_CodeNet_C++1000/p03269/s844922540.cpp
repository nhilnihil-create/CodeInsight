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
#define INF 1000000000000000000//10^18
#define INFINT 2000000001//2*10^9+1
#define MOD 1000000007
#define MODANOTHER 998244353
#define PI acos(-1)

using namespace std;

struct edge{
	int to;
	int cost;
};

int main(void)
{
	//変数の宣言
	int n;
	int dp[30];
	int memo[30];
	struct edge e;
	vector<edge> graph[30];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	ll int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;
	int ok,ng;
	int r;


	//データの読み込み


	scanf("%d",&n);
//	scanf_s("%d",&n);

/*	for(i=0;i<n;i++){
//		scanf("%d",&a[i]);
		scanf_s("%d",&a[i]);
	}*/


	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	i=0;
	while(n>0){
		dp[i]=n%2;
		n=n/2;
		i++;
	}

	len=i;

	for(i=0;i<20;i++){
		memo[i]=dp[i];
	}
	for(i=0;i<20;i++){
		dp[i]=memo[len-i-1];
	}

	temp=(1<<(len-1));
	for(i=1;i<len;i++){
		e.to=i;
		e.cost=0;
		graph[i-1].push_back(e);
		sum++;

		e.cost=(1<<(len-i-1));
		graph[i-1].push_back(e);
		sum++;

		if(dp[i]==1){
			e.to=i;
			e.cost=temp;
			graph[0].push_back(e);
			sum++;
			temp=temp+(1<<(len-i-1));
		}
	}

	


	//	printf("計算部分終了\n");

	//出力

	printf("%d %d\n",len,sum);

	for(i=0;i<len;i++){
		for(j=0;j<graph[i].size();j++){
			e=graph[i][j];
			printf("%d %d %d\n",i+1,e.to+1,e.cost);
		}
	}

	//printf("%d",d[0]);


	//	printf("結果の出力終了\n");


	return 0;
}

