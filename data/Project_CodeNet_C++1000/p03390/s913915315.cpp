
// Problem : D - Worst Case
// Contest : AtCoder - AtCoder Regular Contest 094
// URL : https://atcoder.jp/contests/arc094/tasks/arc094_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define cerr if(1)cerr
#define size(x) (int)x.size()

const int N = 1e6 + 1;

ll a, b;

void solve() {
	cin >> a >> b;
	if (a > b) swap(a, b);
	ll c = sqrt(a * b);
	if (c * c == a * b) c--;
	if (a == b) cout << 2 * (a - 1);
	else if (a + 1 == b) cout << 2 * (a - 1);
	else if (c * (c + 1) >= a * b) cout << 2 * (c - 1);
	else cout << 2 * c - 1;
	cout << '\n';
}

int main() { cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}
