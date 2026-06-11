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
	int n, a, b;
	scanf("%d", &n);
	V links[n];
	rep(i, 0, n-1){
		scanf("%d %d", &a, &b);
		links[a-1].push_back(b-1);
		links[b-1].push_back(a-1);
	}
	V c(n); scan(c);
	std::sort(be(c), std::greater<ll>());

	ll ans[n], used[n];
	memset(ans, 0, sizeof(ans));
	memset(used, 0, sizeof(used));
	std::queue<ll> que;
	que.emplace(0);
	ans[0] = c[0];
	ll cnt = 0, idx = 1;
	while(!que.empty()){
		ll from = que.front();
		que.pop();
		used[from] = 1;
		for(ll to: links[from]){
			if(!used[to]){
				ans[to] = c[idx++];
				que.emplace(to);
				cnt += std::min(ans[from], ans[to]);
			}
		}
	}

	printf("%ld\n", cnt);
	for(ll &i: ans) printf("%ld ", i);
	return 0;
}
