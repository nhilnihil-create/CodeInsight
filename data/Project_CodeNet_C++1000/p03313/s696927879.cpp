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

const int N = (int)(1 << 18) + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

using namespace std;

void upd(int &x, int y) {
	if (x < y) x = y;
}

int m, n;
int a[N], dp[N][2];
int main() {
	#ifdef wws
		freopen ("in.txt", "r", stdin);
	#endif
	Kazakhstan
	cin >> m;
	int n = (1 << m);
	memset(dp, -0x3f, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i][0] = a[i];
	}
	for (int i = 0; i < m; i++) {
		for (int mask = 0; mask < n; mask++) {
			if (mask & (1 << i)) continue;
			upd(dp[mask | (1 << i)][1], dp[mask][0] + dp[mask | (1 << i)][0]);
			upd(dp[mask | (1 << i)][0], dp[mask][0]);
		}
	}
	for (int k = 1; k < n; k++) {
		upd(dp[k][1], dp[k - 1][1]);
		cout << dp[k][1] << nl;
	}
	ioi
}
