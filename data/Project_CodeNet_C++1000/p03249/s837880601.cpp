#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, int> pli;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 100010;

int N;
ll D[MN];
int sz[MN];
vi g[MN];
ll val[MN];

ll sum;

int dfs(int v, int p) {
	int t = 1;
	for (int to : g[v]) if (to != p) {
		int num = dfs(to, v);
		sum += (ll)num * (N - num);
		t += num;
	}
	return t;
}

int main() {
	cin >> N;

	map<ll, int> T;
	rep(i, N) {
		cin >> D[i];
		sz[i] = 1;
		T[D[i]] = i;
	}

	vector<pii> es;

	rep(tt, N - 1) {
		auto it = T.end(); --it;

		int v = it->se;
		ll d = it->fi;
		ll up = d - (N - sz[v] * 2);

		T.erase(d);

		if (!T.count(up)) {
			puts("-1");
			return 0;
		}

		int p = T[up];
		g[p].pb(v);
		g[v].pb(p);
		es.eb(v, p);
		sz[p] += sz[v];
	}

	dfs(0, -1);
	ll s = 0;
	rep(i, N) s += D[i];

	if (s != sum * 2) {
		puts("-1");
		return 0;
	}

	rep(i, N-1) {
		printf("%d %d\n", es[i].fi + 1, es[i].se + 1);
	}

	return 0;
}