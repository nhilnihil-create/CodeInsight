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
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ng = 0, ok = n;
	while (ok - ng > 1) {
		int mid = (ng + ok) / 2;
		vector<P> p;
		bool flag = true;
		rep(i, n) {
			if (i == 0) p.pb(P(1, a[i]));
			else if (a[i - 1] < a[i]) {
				if (p[p.size() - 1].first == 1) {
					p[p.size() - 1].second += a[i] - a[i - 1];
				}
				else {
					p.pb(P(1, a[i] - a[i - 1]));
				}
			}
			else {
				int prev = a[i - 1];
				int num;
				while (prev >= a[i]) {
					prev -= p[p.size() - 1].second;
					num = p[p.size() - 1].first;
					p.pop_back();
				}
				if (num == mid) {
					if (p.size() == 0) {
						flag = false;
						break;
					}
					int pf = p[p.size() - 1].first;
					int ps = p[p.size() - 1].second;
					p.pop_back();
					if (ps > 1) p.pb(P(pf, ps - 1));
					if (p.size() > 0 && p[p.size() - 1].first == pf + 1) p[p.size() - 1].second++;
					else p.pb(P(pf + 1, 1));
					p.pb(P(1, a[i] - prev));
				}
				else {
					if (prev + 1 < a[i]) {
						p.pb(P(num, a[i] - prev - 1));
						p.pb(P(num + 1, 1));
					}
					else {
						if (p[p.size() - 1].first == num + 1) p[p.size() - 1].second++;
						else p.pb(P(num + 1, 1));
					}
				}
			}
		}
		if (flag) ok = mid;
		else ng = mid;
	}
	cout << ok << '\n';
}