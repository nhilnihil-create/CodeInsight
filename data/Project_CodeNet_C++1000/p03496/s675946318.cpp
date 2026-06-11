// スタックサイズ: 100MB

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include <queue>
#include <list>
#include <set>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
const ll INF = 1000000000000000000;
#define fori(i, a, b) for (ll i = (a); i < (b); ++i)
#define ford(i, a, b) for (ll i = (b - 1); (a) <= i; --i)
#define rep(i, n) fori(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define fst first
#define snd second
ll pw(ll x, ll y) { ll r = 1;  rep(i, y) { r *= x; }; return r; }




int main() {

	ll N;
	cin >> N;
	vll a(N);
	rep(i, N) cin >> a[i];

	cout << 2 * N - 2 << endl;
	auto imax = max_element(all(a)), imin = min_element(all(a));
	if (abs(*imin) < abs(*imax)) {
		ll t = imax - a.begin();
		rep(i, N) if (i != t) {
			cout << t + 1 << " " << i + 1 << endl;
		}
		rep(i, N - 1) cout << i + 1 << " " << i + 2 << endl;
	}
	else {
		ll t = imin - a.begin();
		rep(i, N) if (i != t) {
			cout << t + 1 << " " << i + 1 << endl;
		}
		ford(i, 0, N - 1) cout << i + 2 << " " << i + 1 << endl;
	}
}