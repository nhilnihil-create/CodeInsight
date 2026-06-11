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
T GCD(T a, T b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}
template<class T>
T LCM(T a, T b) {
	return a / GCD(a, b) * b;
}
template<class T>
inline T upper(T a, T b) {return (a + (b - 1)) / b; }

constexpr array<int, 9> dx = { 0, 1, 0, -1, -1, 1, 1, -1, 0 };
constexpr array<int, 9> dy = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };

// ──────────────────────────────────────────────────────────────────

int g[101][101];

int main() {
	int a, b;
	cin >> a >> b;

	if (!a) {
		cout << "1 1" << endl << "#" << endl;
	}
	if (!b) {
		cout << "1 1" << endl << "." << endl;
	}

	cout << "100 100" << endl;

	for (int y = 1; y <= 100; ++y) {
		for (int x = 1; x <= 100; ++x) {
			if (y <= 50) g[y][x] = 0;
			else g[y][x] = 1;
		}
	}

	a--, b--;
	for (int y = 1; y <= 50 && b; y += 2) {
		for (int x = 1; x <= 100 && b; x += 2) {
			g[y][x] = 1;
			b--;
		}
	}

	for (int y = 1; y <= 50 && a; y += 2) {
		for (int x = 1; x <= 100 && a; x += 2) {
			g[101 - y][x] = 0;
			a--;
		}
	}

	for (int y = 1; y <= 100; ++y) {
		for (int x = 1; x <= 100; ++x) {
			if (g[y][x] == 1) cout << "#";
			else cout << ".";
		}
		cout << endl;
	}
}
