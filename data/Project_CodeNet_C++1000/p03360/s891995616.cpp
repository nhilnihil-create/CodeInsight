#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;





int main(){

	ll table[3];
	ll maximum = -HUGE_NUM,loc;

	for(int i = 0; i < 3; i++){

		scanf("%lld",&table[i]);
		if(maximum < table[i]){
			maximum = table[i];
			loc = i;
		}
	}

	ll K;
	scanf("%lld",&K);

	for(ll i = 0; i < K; i++){

		maximum *= 2;
	}

	ll ans = maximum;
	for(ll i = 0; i < 3; i++){
		if(i == loc)continue;

		ans += table[i];
	}

	printf("%lld\n",ans);

	return 0;
}
