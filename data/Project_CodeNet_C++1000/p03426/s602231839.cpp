#include "bits/stdc++.h"
using namespace std;

#define ASC(vec) vec.begin(), vec.end()    // 昇順ソート 例：sort(ASC(vec));
#define DESC(vec) vec.rbegin(), vec.rend() // 降順ソート 例：sort(DESC(vec));
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Rep(i, n) for (int i = 1; i < n; i++)
#define REP(i, vec) for (auto i = vec.begin(); i != vec.end(); ++i)

const int       mod = 1000000007;
const int       inf = (1 << 21);
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

template<class T>
inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T>
inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T>
inline T GCD(T a, T b) { return b ? GCD(b, a % b) : a; }
template<class T>
inline T LCM(T a, T b) { return (a + (b - 1)) / b; }
template<class T>
inline T round_int(T a, T b) {return (a + (b - 1)) / b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

int main() {
	int h, w, d;
	cin >> h >> w >> d;

	map<int, ii> info;
	rep(i, h) {
		rep(j, w) {
			int v;
			cin >> v;

			info[v] = make_pair(i, j);
		}
	}

	vector<vector<int>> dist(d, vi(h * w / d + 1));
	for (int i = 1; i <= h * w - d; ++i) {
		ii now = info[i], next = info[i + d];

		int tmp = abs(next.first - now.first) + abs(next.second - now.second);
		dist[i % d][i / d + 1] = tmp + dist[i % d][i / d];
	}

	int q;
	cin >> q;
	vi ans;
	rep(i, q) {
		int x, y;
		cin >> x >> y;
		ans.push_back(dist[y % d][y / d] - dist[x % d][x / d]);
	}
	rep(i, q) cout << ans[i] << endl;
}