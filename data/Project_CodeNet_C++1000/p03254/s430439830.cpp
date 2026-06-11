#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[130]; 
int main() {
	int n, x;
	cin >> n >> x;
	rep(i,n) cin >> a[i];
	sort(a,a+n);

	int ans = 0;
	rep(i,n) {
		if (i < n-1) {
			if (x >= a[i]) {
				ans++;
				x -= a[i];
			}
		} else {
			if (x == a[i]) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}