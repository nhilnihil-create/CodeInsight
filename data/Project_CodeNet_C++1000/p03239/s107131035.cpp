#pragma target("avx")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define rep(i,b,e) for(ll i=b; i<e; i++)
#define be(vec) vec.begin(),vec.end()
#define print(vec) for(auto &i:vec)fprintf(stderr,"%ld ",i);puts("");
#define scan(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	int n, t, ans = 2e9;
	scanf("%d %d", &n, &t);
	rep(i, 0, n){
		int c, v;
		scanf("%d %d", &c, &v);
		if(v<=t) ans = std::min(ans, c);
	}
	if(ans>10000) puts("TLE");
	else printf("%d\n", ans);
	return 0;
}
