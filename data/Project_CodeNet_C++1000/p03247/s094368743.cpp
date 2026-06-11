#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	bool odd = true, even = true;
	rep(i, n) {
		cin >> x[i] >> y[i];
		if ((x[i] + y[i]) % 2 == 0) odd = false;
		else even = false;
	}
	if (!odd && !even) {
		cout << "-1\n";
		return 0;
	}
	cout << (odd ? 39 : 40) << '\n';
	vector<ll> dis;
	vector<string> w(n);
	ll d = 1ll << 38;
	bool flag = true;
	while (d) {
		dis.pb(d);
		rep(i, n) {
			if (abs(x[i]) < abs(y[i])) {
				if (y[i] > 0) w[i] += 'U', y[i] -= d;
				else w[i] += 'D', y[i] += d;
			}
			else {
				if (x[i] > 0) w[i] += 'R', x[i] -= d;
				else w[i] += 'L', x[i] += d;
			}
		}
		d >>= 1;
		if (d == 0 && even && flag) { d = 1, flag = false; }
	}
	for (ll i : dis) cout << i << ' '; cout << '\n';
	for (string s : w) cout << s << '\n';
}