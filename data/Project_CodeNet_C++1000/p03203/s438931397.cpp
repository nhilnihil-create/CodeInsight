#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <iomanip>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2")
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long double ld;
typedef long long ll;
typedef double db;
#define endl '\n'
#define pb push_back
#define pii pair<ll, ll>
#define ff first
#define ss second
#define sz(x) (ll)(x).size()
#define optimize1() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma warning(disable:4996)

using namespace std;

const ll MX = 1e6 + 10, INF = 1e9 + 1;
ll n, m, k, x, y, ans = 0;
vector<pii> sp;
signed main() {
	optimize1();
	cin >> n >> m >> k;
	ans = n;
	for (ll i = 0; i < k; ++i) {
		cin >> x >> y;
		sp.pb({ x, y });
	}
	ll res = 0;
	sort(all(sp));
	for (auto& c : sp) {
		x = c.ff;
		y = c.ss;
		if (x > y + res)
			ans = min(ans, x - 1);
		if (x == y + res)
			res++;
	}
	cout << ans << endl;
	return 0;
}