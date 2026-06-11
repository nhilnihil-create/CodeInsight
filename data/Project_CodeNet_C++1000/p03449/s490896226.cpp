#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int n;
	cin >> n;
	int cum1[101], cum2[101];
	int a1[101], a2[101];
	rep(i, n) cin >> a1[i];
	rep(i, n) cin >> a2[i];
	rep(i, n) {
		if (i==0) {
			cum1[i] = a1[i];
			cum2[i] = a2[i];
		} else {
			cum1[i] = cum1[i-1] + a1[i];
			cum2[i] = cum2[i-1] + a2[i];
		}
	}
	int ans = 0;
	rep(i, n) {
		int now = cum1[i] + a2[i] + (cum2[n-1] - cum2[i]);
		ans = max(ans, now);
	}

	cout << ans << endl;
	return 0;
}