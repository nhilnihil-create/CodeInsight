#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<vector<int>> dist(10, vector<int>(10, inf));
	rep(i, 10)rep(j, 10) {
		int a;
		cin >> a;
		dist[i][j] = a;
	}
	rep(k, 10)rep(i, 10)rep(j, 10) {
		mins(dist[i][j], dist[i][k] + dist[k][j]);
	}
	vector<vector<int>> mp(h, vector<int>(w));
	rep(i, h)rep(j, w) cin >> mp[i][j];
	int ans = 0;
	rep(i, h)rep(j, w) {
		if (mp[i][j] == -1) continue;
		ans += dist[mp[i][j]][1];
	}
	cout << ans << endl;
	return 0;
}
