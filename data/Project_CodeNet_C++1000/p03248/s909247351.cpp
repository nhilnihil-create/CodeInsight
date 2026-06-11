/// In The Name Of God

#include <bits/stdc++.h>

#define f first
#define s second

#define pb push_back
#define pp pop_back
#define mp make_pair

#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()

#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)

#define Kazakhstan ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);

#define nl '\n'
#define ioi exit(0);

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

int n, id = 1;
char s[N];
vector <int> g[N];
void go(int v, int p, int size) {
	if (p) {
		g[v].pb(p);
		g[p].pb(v);
	}
	if (p && s[size] == '0') {
		cout << -1, ioi
	}
	if (!p && s[size] == '1') cout << -1, ioi
	
	while (size > 1) {
		if (s[size - 1] == '1') {
			go(++id, v, size - 1);
			return;
		} else if (s[1] == '1') {
			go(++id, v, 1);
			--size;
		} else break;
	}
}
int main() {
	#ifdef wws
		freopen ("in.txt", "r", stdin);
	#endif
	cin >> (s + 1);
	n = strlen(s + 1);
	rep(i, 1, n - 1) if (s[i] != s[n - i]) cout << -1, ioi
	go(1, 0, n);
	if (id != n) cout << -1, ioi
	rep(i, 1, n) {
		sort(all(g[i]));
		g[i].erase(unique(all(g[i])), g[i].end());
		for (auto to : g[i]) if (i < to) cout << i << ' ' << to << nl;
	}
	ioi
}
