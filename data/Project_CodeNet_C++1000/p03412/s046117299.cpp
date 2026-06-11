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
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
typedef complex<double> com;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	sort(all(a)); sort(all(b));
	int ans = 0;
	for (int i = 29; i >= 0; i--) {
		int x = (1 << i);
		int y = (1 << (i + 1));
		rep(j, n) {
			int cntx = lower_bound(all(b), x - a[j] % y) - b.begin();
			int cnty = lower_bound(all(b), y - a[j] % y) - b.begin();
			cntx += lower_bound(all(b), x + y - a[j] % y) - b.begin();
			cnty += lower_bound(all(b), 2 * y - a[j] % y) - b.begin();
			int cnt = (cnty - cntx) & 1;
			if (cnt) ans ^= x;
		}
		rep(j, n) b[j] %= x;
		sort(all(b));
	}
	cout << ans << endl;
} 