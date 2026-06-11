//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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



int main(void)
{
	//変数の宣言
	int n,m;
	char s[3][10];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp=0;
	int temp1=0;
	int temp2=0;
	int temp3=0;
	int max=0;
	int min=INFINT;
	int len=0;
	int sum=0;
	int ok=0;
	int ng=0;
	char dummy;
	char stemp[11];
	
	//データの読み込み


	scanf("%d",&n);
//	scanf_s("%d",&n);

//	scanf("%s",&s);
//	scanf_s("%s",&s,10);


/*	for(i=0;i<n;i++){
//		scanf("%d",&b[i]);
		scanf_s("%d",&b[i]);
	}*/


/*	for(i=0;i<3;i++){
//		scanf("%s",&s);
		scanf_s("%s",&s[i],10);
	}*/


	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

//	clock_t start=clock();

	printf("%d",n/3);

//	clock_t end=clock();

	//	printf("計算部分終了\n");

	//出力
	//printf("%d",min(sum+2*m,n-1));

//	printf("time=%lf",(double)(end-start)/CLOCKS_PER_SEC);
	//	printf("結果の出力終了\n");

	return 0;
}

