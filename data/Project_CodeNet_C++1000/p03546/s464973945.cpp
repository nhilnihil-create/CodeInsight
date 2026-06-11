#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const int MOD = 1e9+7;

int main() {

	int h, w; cin >> h >> w;
	vector<vector<int>> a(10, vector<int>(10));
	rep(i, 10) rep(j, 10) cin >> a[i][j];

	rep(k, 10) {
		rep(i, 10) rep(j, 10) {
			a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
		}
	}

	// rep(i, 10) rep(j, 10) cout << a[i][j] << ((j==9)?"\n":" ");

	int ans = 0;
	rep(i, h*w) {
		int x; cin >> x;
		if(x==-1 || x==1) continue;
		ans += a[x][1];
	}

	cout << ans << endl;
}