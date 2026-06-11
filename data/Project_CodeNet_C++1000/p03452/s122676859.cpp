#pragma target("avx")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define rep(i,b,e) for(ll i=b; i<e; i++)
#define be(vec) vec.begin(),vec.end()
#define print(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define scan(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	ll n, m;
	scanf("%ld %ld", &n, &m);

	std::vector<P> links[n];
	while(m--){
		ll l, r, d;
		scanf("%ld %ld %ld", &l, &r, &d);
		links[l-1].emplace_back(r-1, d);
		links[r-1].emplace_back(l-1, -d);
	}

	bool ok = true;
	V coo(n, -1), used(n, 0);

	rep(i, 0, n){
		if(used[i]) continue;
		std::queue<P> que;
		que.emplace(i, 0);
		while(!que.empty()){
			P p = que.front();
			que.pop();
			if(used[p.fi]) continue;
			used[p.fi] = true;
			coo[p.fi] = p.se;
			for(P to: links[p.fi]){
				if(!used[to.fi]) que.emplace(to.fi, p.se+to.se);
				else if(coo[to.fi]!=p.se+to.se) ok = false;
			}
		}
	}

	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
