#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[10010], b[10010];
int main() {
	int n;
	cin >> n;
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	ll l = 0, r = 0;
	rep(i,n) {
		if (a[i] > b[i]) l += a[i] - b[i];
		if (a[i] < b[i]) {
			r += (b[i]-a[i]) / 2;
			
		}
	}
	if (l <= r) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}