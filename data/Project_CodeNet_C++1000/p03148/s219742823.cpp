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
#define debug(x) cerr << __LINE__ << ' ' << #x << ':' << x << '\n'
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


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	ll n, k;
	cin >> n >> k;
	vector<P> p(n);
	rep(i, n) {
		cin >> p[i].first >> p[i].second;
		p[i].first--;
	}
	sort(all(p), [](P a, P b) {return a.second > b.second; });
	priority_queue<P, vector<P>, greater<P>> que;
	ll sum = 0; ll v = 0;
	vector<ll> cnt(n);
	rep(i, k) {
		int x = p[i].first;
		sum += p[i].second;
		if (cnt[x] > 0) {
			que.push({ p[i].second,x });
		}
		else v++;
		cnt[x]++;
	}
	ll ans = sum + v * v;
	for (int i = k; i < n; i++) {
		int x = p[i].first;
		if (cnt[x] == 0 && !que.empty()) {
			P q = que.top(); que.pop();
			sum -= q.first; sum += p[i].second;
			v++;
			cnt[q.second]--;
			cnt[x]++;
			chmax(ans, sum + v * v);
		}
	}
	cout << ans << '\n';
}