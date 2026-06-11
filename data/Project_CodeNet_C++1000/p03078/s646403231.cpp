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
	ll x, y, z, k;
	scanf("%ld %ld %ld %ld", &x, &y, &z, &k);
	V a(x), b(y), c(z);
	SCAN(a); SCAN(b); SCAN(c);

	V d;
	REP(i, 0, x) REP(j, 0, y) {
		d.push_back(a[i]+b[j]);
	}
	std::sort(ALL(d), std::greater<ll>());
	ll min = std::min(k, (ll)d.size());
	V e;
	REP(i, 0, min) REP(j, 0, z) {
		e.push_back(d[i]+c[j]);
	}
	std::sort(ALL(e), std::greater<ll>());
	REP(i, 0, k) printf("%ld\n", e[i]);
	return 0;
}

