#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	ll N,K;
	scanf("%lld %lld",&N,&K);

	if(K%2 == 0){

		ll num = 0;
		ll num2 = 0;
		ll half_K = K/2;

		for(ll i = 1; i <= N; i++){

			if(i%K == 0){

				num++;
			}else if(i%(half_K) == 0){

				num2++;
			}
		}

		printf("%lld\n",num*num*num+num2*num2*num2);

	}else{

		ll num = 0;

		for(ll i = 1; i <= N; i++){

			if(i%K == 0)num++;
		}

		printf("%lld\n",num*num*num);
	}

	return 0;
}
