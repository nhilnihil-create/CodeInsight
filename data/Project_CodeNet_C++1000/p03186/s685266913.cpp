/* it was worth becoming a chemist */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<int, long long> pil;
typedef vector<int> vi;
typedef vector<long long> vll;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define NAME "puts"
#define F first
#define S second

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

ll a, b, c;

void solve() {
	cin >> a >> b >> c;
	ll mn = min(a, c);
	ll res = mn;
	a -= mn;
	c -= mn;
	if (b >= c) cout << res + b + c;
	else cout << res + b * 2 + 1;
}


main() {
	

	ios_base::sync_with_stdio(0);
	cin.tie(0);            	
	cout.tie(0);

	int times = 1;
	for (int i = 1; i <= times; i++) {
		solve();
	}

	return 0;	
}	