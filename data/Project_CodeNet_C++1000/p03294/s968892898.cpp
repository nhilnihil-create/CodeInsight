#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



ll N;
ll A[3005];

int main(){

	scanf("%lld",&N);

	ll ans = 0;

	/*
	 * mを前部の数の最小公倍数-1とすれば良い
	 *
	 *
	 * */
	for(ll i = 0; i < N; i++){

		scanf("%lld",&A[i]);
		ans += A[i]-1;
	}

	printf("%lld\n",ans);

	return 0;
}
