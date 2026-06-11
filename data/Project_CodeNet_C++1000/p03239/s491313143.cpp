#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int N,T;

	scanf("%d %d",&N,&T);

	int minimum = BIG_NUM;

	int cost,tmp;

	for(int i = 0; i < N; i++){

		scanf("%d %d",&cost,&tmp);
		if(tmp > T)continue;

		minimum = min(minimum,cost);
	}

	if(minimum == BIG_NUM){

		printf("TLE\n");

	}else{

		printf("%d\n",minimum);
	}

	return 0;
}
