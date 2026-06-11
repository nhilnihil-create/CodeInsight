#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()		// 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend()	// 降順ソート 例:sort(DESC(vec));
#define rep(i, n) for(int i = 0; i < (n); i++)
#define Rep(i, n) for(int i = 1; i < n; i++)
#define REP(i, vec) for(auto i = vec.begin(); i != vec.end(); ++i)

const int mod = 1000000007;
const int inf = (1 << 21);
const long long INF = 1LL << 60;

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vd = vector<double>;
using vb = vector<bool>;
using vl = vector<ll>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
using vii = vector<pair<int, int>>;
using vll = vector<pair<ll, ll>>;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline T GCD(T a, T b) { return b ? GCD(b, a % b) : a; }
template<class T> inline T LCM(T a, T b) { return (a + (b - 1)) / b; }

int round_int(int a, int b) { return (a + (b - 1)) / b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

int main() {
	int a, b, q;
	cin >> a >> b >> q;

	vl s(a), t(b), x(q), dist(a + b), nor;
	vll all;

	rep(i, a) {
		cin >> s[i];
		all.push_back({ s[i],0 });
		nor.push_back(s[i]);
	}
	rep(i, b) {
		cin >> t[i];
		all.push_back({ t[i],1 });
		nor.push_back(t[i]);
	}
	rep(i, q) {
		cin >> x[i];
	}

	sort(ASC(s));
	sort(ASC(t));
	sort(ASC(all));
	sort(ASC(nor));

	rep(i, a + b) {
		pair<ll, ll> p = all[i];

		// p = shrine
		if (p.second == 0) {
			int idx = upper_bound(ASC(t), p.first) - t.begin();

			ll mn = INF, mx = INF;
			if (idx != 0) {
				mn = abs(t[idx - 1] - p.first);
			}
			if (idx != b) {
				mx = abs(t[idx] - p.first);
			}

			dist[i] = min(mn, mx);
		}
		else {
			int idx = upper_bound(ASC(s), p.first) - s.begin();

			ll mn = INF, mx = INF;
			if (idx != 0) {
				mn = abs(s[idx - 1] - p.first);
			}
			if (idx != a) {
				mx = abs(s[idx] - p.first);
			}

			dist[i] = min(mn, mx);
		}
	}

	rep(i, q) {
		int idx = upper_bound(ASC(nor), x[i]) - nor.begin();

		ll mn = INF, mx = INF;
		ll ans1 = INF, ans2 = INF;
		if (idx != 0) {
			mn = abs(nor[idx - 1] - x[i]);
			ans1 = mn + dist[idx - 1];
		}
		if (idx != a + b) {
			mx = abs(nor[idx] - x[i]);
			ans2 = mx + dist[idx];
		}
		
		cout << min(ans1, ans2) << endl;
	}
}