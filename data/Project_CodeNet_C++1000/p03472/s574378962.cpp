#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int n, h, ans=0;
	cin >> n >> h;
	vector<int> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	int m = 0;
	rep(i,n) m = max(m,a[i]);
	sort(b.begin(), b.end());
	int i = n - 1;
	while (h > 0) {
		if (b[i] > m && i >= 0) {
			h -= b[i];
			i--;
			ans++;
		}
		else {
			ans += (h + m - 1) / m;
			h = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
