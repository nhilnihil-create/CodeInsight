#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	ll N;
	scanf("%lld",&N);

	if(N == 0){

		printf("0\n");
		return 0;
	}

	stack<ll> S;

	while(N != 0){

		if(N%2 != 0){
			N--;
			S.push(1);
		}else{

			S.push(0);
		}
		N /= -2;
	}

	while(!S.empty()){

		printf("%lld",S.top());
		S.pop();
	}

	printf("\n");

	return 0;
}
