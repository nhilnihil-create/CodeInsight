#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


ll N,M;
ll table[100005];
map<ll,ll> MAP;

int main(){

	scanf("%lld %lld",&N,&M);

	table[0] = 0;
	MAP[0]++;

	ll ans = 0;

	for(ll i = 1; i <= N; i++){

		scanf("%lld",&table[i]);
		table[i] += table[i-1];
		table[i] %= M;

		ans += MAP[table[i]];
		MAP[table[i]]++;
	}

	printf("%lld\n",ans);

	return 0;
}
