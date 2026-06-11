#include <bits/stdc++.h>

#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define all(v) v.begin(), v.end()
#define ar array

#define F first
#define S second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using ld = long double;

const int mod = 1e9 + 7;
// const int mod = 998244353;
const ll inf = 2e9;
const ll INF = 1e18;
const ld EPS = 1e-7;

const int N = 1e5 + 5;

int i (char x) {
	return x - '0';
}

void solve () {
	string SS;
	cin >> SS;
	int f = i(SS[0]) * 10 + i(SS[1]), s = i(SS[2]) * 10 + i(SS[3]);
	if (f <= 12 && s <= 12 && min (f, s) >= 1) {
		cout << "AMBIGUOUS";
	}
	else if (f <= 12 && f) {
		cout << "MMYY";
	}
	else if (s <= 12 && s) {
		cout << "YYMM";
	}
	else {
		cout << "NA";
	}
}

int main () {
	ios;
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
		cout << "\n";
	}
}


