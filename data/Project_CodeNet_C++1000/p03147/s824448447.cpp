#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	ans = h[0];
	for (int i = 1; i < n; i++) {
		if (h[i - 1] < h[i]) ans += (h[i] - h[i - 1]);
	}
	cout << ans;
	return 0;
}