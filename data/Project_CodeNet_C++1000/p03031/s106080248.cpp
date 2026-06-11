#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = n; i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;

int p[11];
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> s(n);
	rep(i,m) {
		int k; cin >> k;
		rep(j,k) {
			int ss; cin >> ss;
			s[ss-1].push_back(i);
		}
	}
	int ans = 0;
	rep(i,m) cin >> p[i];
	rep(t, 1<<n) {
		vector<int> light(10,0);
		rep(i,n) {
			if (t>>i & 1) {for (int v: s[i]) light[v]++;}
		}
		bool can = true;
		rep(i,m) if (light[i]%2 != p[i]) {can = false; break;}
		if (can) ans++;
	}
	cout << ans << endl;
	return 0;
}