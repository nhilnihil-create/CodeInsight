#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <iomanip>
//#include <cmath>
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

const ll MX = 5e4 + 10, INF = 1e9 + 1;
ll n;
vector<vector<int>> a;
vector<int> cur(20, 0);

bool can(int l) {
	for (int i = 0; i <= 20; ++i)
		if (cur[i] + a[l][i] == 2)
			return false;
	return true;
}

signed main() {
	optimize1();
	cin >> n;
	a.resize(n);
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		for (int j = 0; j <= 20; ++j) {
			a[i].pb(x % 2);
			x /= 2;
		}
	}
	ll ans = 0, l = 0;
	for (int i = 0; i < n; ++i) {
		while (l < n && can(l)) {
			for (int j = 0; j <= 20; ++j)
				cur[j] += a[l][j];
			l++;
		}
		//cout << i << ' ' << l << endl;
		ans += l - i;
		for (int j = 0; j <= 20; ++j)
			cur[j] -= a[i][j];
	}
	cout << ans << endl;
	return 0;
}