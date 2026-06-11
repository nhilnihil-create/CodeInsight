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

using pint = pair<int, int>;
using ppint = pair<pint, pint>;

int main() {
	int h, w;
	cin >> h >> w;

	int odd = 0;
	vvi a(h, vi(w));
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
			if (a[i][j] & 1) ++odd;
		}
	}

	vector<ppint> res;
	int num = 0;
	int x = 0, y = 0;
	rep(_, w* h) {
		if (a[x][y] & 1) ++num;

		int nx = x, ny = y;
		if (x % 2 == 0) {
			if (ny == w - 1) ++nx;
			else ++ny;
		}
		else {
			if (ny == 0) ++nx;
			else ny--;
		}

		if (num & 1) {
			if (num < odd) {
				res.push_back(ppint(ii(x, y), ii(nx, ny)));
			}
		}
		x = nx, y = ny;
	}
	cout << res.size() << endl;
	for (auto p : res) {
		cout << p.first.first + 1 << " " << p.first.second + 1 << " " << p.second.first + 1 << " " << p.second.second + 1 << endl;
	}

}