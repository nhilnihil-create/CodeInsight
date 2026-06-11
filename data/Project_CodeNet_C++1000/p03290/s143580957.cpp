#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
int p[10], c[10]; 
int main() {
	int d, g;
	cin >> d >> g;
	rep(i,d) cin >> p[i] >> c[i];
	int ans = INF;

	rep(s, 1<<d) {
		int now = 0, cnt = 0, imcomplete = 0, idx = -1;
		rep(i,d) {
			if ((s>>i) & 1) {
				now += 100 * (i+1) * p[i] + c[i];
				cnt += p[i];
			} else {
				imcomplete = 100*(i+1);
				idx = i;
			} 
		}
		if (now < g) {
			int rem = g - now;
			int pl = (rem + imcomplete -1) / imcomplete;
			if (pl > p[idx]) continue;
			cnt += pl;
		}
		
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}