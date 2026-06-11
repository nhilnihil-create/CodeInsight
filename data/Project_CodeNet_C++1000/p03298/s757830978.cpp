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
#define ALL(a) (a).begin(),(a).end()

using namespace std;


struct kouzou_t{
	string str;	
	int idnum;

/*	bool operator<(const kouzou_t& another) const {
		int x=str.compare(another.str);
		if(x==1) return 1;
		return 0;
	}*/
};

int asc(const void *a, const void *b) {
	struct kouzou_t *A = (struct kouzou_t *)a;
	struct kouzou_t *B = (struct kouzou_t *)b;
	return B->str.compare(A->str);
}


int main(void)
{
	//変数の宣言
	int n;
	char s[40];
//	string str;
	struct kouzou_t memo;
	static struct kouzou_t dp[300000];
	struct kouzou_t kouzou;
	int ng,ok;

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

	scanf("%s",&s);
//	scanf_s("%s",&s,40);

//	for(i=1;i<=n;i++){
//		scanf("%lld %lld %d",&x[i],&y[i],&r[i]);
//		scanf_s("%lld %lld %d",&x[i],&y[i],&r[i]);
//	}
	
	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	for(i=0;i<(1<<n);i++){
		temp=0;
		for(j=0;j<n;j++){
			if((i&(1<<j))==0){
				kouzou.str.push_back(s[j]);
				temp++;
			}
		}
		kouzou.str.push_back(',');
		for(j=0;j<n;j++){
			if((i&(1<<j))!=0){
				kouzou.str.push_back(s[j]);
			}
		}

//		printf("%s\n",kouzou.str.c_str());

		dp[i].str=kouzou.str;
		dp[i].idnum=1;
		kouzou.str.erase(kouzou.str.begin(),kouzou.str.end());
		
	}

	
/*	for(auto itr=dp.begin();itr!=dp.end();++itr){
		memo=*itr;
		printf("%s\n",memo.str.c_str());
	}
*/
	qsort(dp,(1<<n),sizeof(kouzou_t),asc);

	for(i=0;i<(1<<n);i++){
		dp[i].idnum=i;
	}

/*	for(auto itr=dp.begin();itr!=dp.end();++itr){
		memo=*itr;
		printf("%s\n",memo.str.c_str());
	}
*/




	for(i=0;i<(1<<n);i++){
		for(j=0;j<n;j++){
			if((i&(1<<j))==0){
				kouzou.str.push_back(s[2*n-1-j]);
			}
		}
		kouzou.str.push_back(',');
		for(j=0;j<n;j++){
			if((i&(1<<j))!=0){
				kouzou.str.push_back(s[2*n-1-j]);
			}
		}

		ng=-1;
		ok=(1<<n);
		while(ok-ng>1){
//			printf("%d\n",dp[(ok+ng)/2].str.compare(kouzou.str));
			if(dp[(ok+ng)/2].str.compare(kouzou.str)>0){
				ng=(ok+ng)/2;
			}else{
				ok=(ok+ng)/2;
			}
		}
		ans=ans-ok;
		
		ng=-1;
		ok=(1<<n);
		while(ok-ng>1){
			if(dp[(ok+ng)/2].str.compare(kouzou.str)>=0){
				ng=(ok+ng)/2;
			}else{
				ok=(ok+ng)/2;
			}
		}
		ans=ans+ok;
		
		kouzou.str.erase(kouzou.str.begin(),kouzou.str.end());
	}


	//	printf("計算部分終了\n");

	//出力

	printf("%lld",ans);

	//	printf("結果の出力終了\n");


	return 0;
}

