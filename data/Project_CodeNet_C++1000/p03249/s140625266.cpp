#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;

int n;
int sz[maxn];
ll a[maxn], dis[maxn];
vector<pair<ll, int> > ord;
map<ll, int> mp;
vector<int> g[maxn];

inline void dfs(int u, int p){
	dis[u] = 0;
	//printf("u = %d sz = %d\n", u, sz[u]);
	FOR(i, 0, g[u].size()){
		int v = g[u][i];
		if(v == p) continue;
		dfs(v, u);
		dis[u] += dis[v] + sz[v];
	}
	return;
}

int main(){
	scanf("%d", &n);
	FOR(i, 0, n){
		scanf("%lld", a + i);
		ord.PB(MP(a[i], i));
		mp[a[i]] = i;
	}
	sort(ord.begin(), ord.end());
	FOR(i, 0, n) sz[i] = 1;
	for(int i = ord.size() - 1; i >= 0; --i){
		int u = ord[i].snd;
		ll d = ord[i].fst;
		//printf("i = %d\n", i);
		if(!i){
			dfs(u, -1);
			if(dis[u] != d){
				//FOR(i, 0, n) printf("%lld ", dis[u]); puts("");
				//printf("::%lld %lld\n", dis[u], d);
				puts("-1");
				return 0;
			}
			break;
		}
		//printf("%lld %lld\n", d, d - n + sz[u] * 2);
		if(mp.find(d - n + sz[u] * 2) != mp.end()){
			int p = mp[d - n + sz[u] * 2];
			//printf("p = %d u = %d\n", p, u);
			sz[p] += sz[u];
			g[p].PB(u);
			g[u].PB(p);
		}
		else{
			puts("-1");
			return 0;
		}
	}
	FOR(u, 0, n) FOR(i, 0, g[u].size()){
		int v = g[u][i];
		if(u < v) printf("%d %d\n", u + 1, v + 1);
	}
	return 0;
}