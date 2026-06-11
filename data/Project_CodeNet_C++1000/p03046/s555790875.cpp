#pragma target("avx")
#pragma optimize("O3")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using PP = std::pair<ll,P>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define REP(i,b,e) for(ll i=b; i<e; i++)
#define ALL(vec) vec.begin(),vec.end()
#define PRINT(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define SCAN(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	ll m, k;
	scanf("%ld %ld", &m, &k);
	if(k==0){
		ll ans[1<<(m+1)], val = 0;
		REP(i, 0, 1<<m) ans[(1<<m)+i] = ans[(1<<m)-i-1] = val++;
		REP(i, 0, 1<<(m+1)) printf("%ld ", ans[i]); puts("");
		return 0;
	}

	ll x = 0;
	REP(i, 0, 1<<m) if(i!=k) x ^= i;
	if(x!=k) puts("-1");
	else{
		ll ans[1<<(m+1)], val = 0;
		REP(i, 0, 1<<m){
			ans[(1<<m)+i+1] = ans[(1<<m)-i-1] = val;
			val++;
			if(val==k) val++;
		}
		ans[0] = ans[1<<m] = k;
		REP(i, 0, 1<<(m+1)) printf("%ld ", ans[i]); puts("");
	}

	return 0;
}

