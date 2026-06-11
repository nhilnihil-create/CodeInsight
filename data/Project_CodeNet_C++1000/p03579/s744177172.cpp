#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

const int maxn = 100010;

V<int> g[maxn];
int st[maxn];

void dfs(int v, int c) {
	st[v] = c;
	for (int to : g[v]) {
		if (st[to] == -1) {
			dfs(to, c ^ 1);
		}
	}
}

int main() {
	int N, M; cin >> N >> M;
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(st, -1, sizeof(st));

	dfs(0, 0);

	bool bi = 1;
	int cnt = 0;
	rep(i, N) {
		if (st[i]) ++cnt;
		for (int to : g[i]) {
			if (st[i] == st[to]) {
				bi = 0;
			}
		}
	}

	if (bi) {
		cout << (ll)cnt * (N - cnt) - M << endl;
	} else {
		cout << (ll)N * (N - 1) / 2 - M << endl;
	}

	return 0;
}