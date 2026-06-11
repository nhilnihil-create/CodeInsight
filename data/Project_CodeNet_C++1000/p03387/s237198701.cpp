#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	vector <int> x(3);
	rep(i,3) cin >> x[i];
	sort(x.begin(), x.end());
	int ans = 0;
	while (x[0] < x[2] - 1) {
		x[0] += 2;
		ans++;
	}
	while (x[1] < x[2] - 1) {
		x[1] += 2;
		ans++;
	}
	sort(x.begin(), x.end());
	if (x[0] < x[1]) ans += 2;
	if (x[1] < x[2]) ans++;
	cout << ans;
	return 0;
}