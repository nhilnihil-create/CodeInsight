#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int n;
	cin >> n;
	int x[101], y[101], h[101];
	rep(i, n) cin >> x[i] >> y[i] >> h[i];
	rep(cx, 101) rep(cy, 101) {
		int t;
	       	rep(i, n) {
			if (h[i] > 0) {
				t = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
				break;
			}
		}
		bool ok = true;
		rep(i, n) {
			if (max(0, t - abs(x[i]-cx) - abs(y[i]-cy)) != h[i]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << cx << ' ' << cy << ' ' << t << endl;
		}
	}

	
}
