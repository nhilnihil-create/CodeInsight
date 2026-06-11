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

#define int ll

int n;
int x[N], y[N];
int mx;
vector <int> ans;
int32_t main() {
	#ifdef wws
		freopen ("in.txt", "r", stdin);
	#endif
	cin >> n;
	set <int> st;
	rep(i, 1, n) {
		cin >> x[i] >> y[i];
		st.insert((x[i] + y[i]) & 1);
		mx = max(mx, x[i] + y[i]);
	}
	if (sz(st) == 2) cout << -1, ioi
	ll sum = 0;
	if (*st.begin() == 0) {
		ans.pb(1);
		++sum;
	}
	ll id = 1;
	while (sum < mx) {
		ans.pb(id);
		sum += id;
		id <<= 1;
	}
	cout << sz(ans) << nl;
	for (auto it : ans) cout << it << ' ';
	cout << nl;
	reverse(all(ans));

	auto good = [&] (int x, int y, int z) {
		return abs(x) + abs(y) <= z;
	};

	rep(i, 1, n) {
		int cur = sum;
		int cx = x[i], cy = y[i];
		string s;
		for (auto it : ans) {
			cur -= it;
			if (good(cx + it, cy, cur)) {
				cx += it;
				s += 'L';
			} else if (good(cx - it, cy, cur)) {
				cx -= it;
				s += 'R';
			} else if (good(cx, cy + it, cur)) {
				cy += it;
				s += 'D';
			} else {
				cy -= it;
				s += 'U';
			}
		}
		reverse(all(s));
		cout << s << nl;
	}
	ioi
}
