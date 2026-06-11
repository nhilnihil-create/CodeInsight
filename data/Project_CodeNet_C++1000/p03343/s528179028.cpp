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
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
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
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ans = INF;
	rep(i, n) {
		vector<int> ok;
		multiset<int> st;
		rep(j, n) {
			if (a[j] < a[i]) st.clear();
			else {
				st.insert(a[j]);
				if (st.size() >= k) {
					auto p = st.begin();
					ok.pb(*p);
					p = st.erase(p);
				}
			}
		}
		if (ok.size() >= q) {
			sort(all(ok));
			chmin(ans, ok[q - 1] - ok[0]);
		}
	}
	cout << ans << endl;
}