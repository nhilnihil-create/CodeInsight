#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int N,M,X;
	scanf("%d %d %d",&N,&M,&X);

	int table[N+1];
	for(int i = 0; i <= N; i++){

		table[i] = 0;
	}

	int tmp;
	for(int i = 0; i < M; i++){

		scanf("%d",&tmp);
		table[tmp] = 1;
	}

	int L = 0, R = 0;

	for(int i = X-1; i >= 0; i--){

		L += table[i];
	}
	for(int i = X+1; i <= N; i++){

		R += table[i];
	}

	printf("%d\n",min(L,R));

	return 0;
}
