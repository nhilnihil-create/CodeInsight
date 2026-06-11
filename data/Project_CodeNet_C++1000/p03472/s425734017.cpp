#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int a[100010], b[100010];
int main() {
	int n, h;
	cin >> n >> h;
	rep(i,n) cin >> a[i] >> b[i];
	//sort(a,a+n,greater<int>());
	sort(b,b+n,greater<int>());
	
	int ma = *max_element(a,a+n);
	int k = -1;
	rep(i,n) {
		if (b[i] <= ma) {
			k = i;
			break;
		}
	}

	int ans = 0;
	if (k == -1) {
		rep(i,n) {
			h -= b[i];
			ans++;
			if (h <= 0) {
				cout << ans << endl;
				return 0;
			}
		}
		ans += (h+ma-1) / ma;
	}
	else {
		rep(i,k) {
			h -= b[i];
			ans++;
			if (h <= 0) {
				cout << ans << endl;
				return 0;
			}
		}
		ans += (h+ma-1) / ma;
		
	}
	cout << ans << endl;
	return 0;
}