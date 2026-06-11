#pragma GCC optimize ("Ofast")
#include "bits/stdc++.h"
	
#define PI 3.141592653589793
#define FAST ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
// Use for file I/O;
#define FIN string _fname = ""; \
			string _is = _fname + ".in", _os = _fname + ".out"; \
			freopen(_is.c_str(), "r", stdin); \
			freopen(_os.c_str(), "w", stdout);
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
 
using namespace std;
 
const ll INF = 1e9 + 10;
const ll INF2 = 1e18 + 10;
const int MOD = 1e9 + 7;
const ld EPS = 1e-4;
 
const int LOGN = 19;
const int MAXN = 2e5;
 
bool cmp(const vector<ll> &a, const vector<ll> &b) {
	return a[0] + a[1] < b[0] + b[1];
}
 
int main() {
	FAST;
 
	int n;
	cin >> n;
	
	vector<vector<ll>> a(n, vector<ll>(3));
	for (int i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	sort(a.begin(), a.end(), cmp);

	int mw = 20000;

	vector<ll> dp(mw + 1);

	for (int i = 0; i < n; i++) {
		for (int j = mw/2; j >= 0; j--) {
			if (j <= a[i][1]) dp[j + a[i][0]] = max(dp[j + a[i][0]], dp[j] + a[i][2]);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}