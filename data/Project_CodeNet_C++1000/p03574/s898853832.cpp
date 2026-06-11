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
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	const int dx[] = { 0,1,0,-1 ,1,-1,1,-1};
	const int dy[] = { 1,0,-1,0 ,1,-1,-1,1};
	vector<vector<int>> ans(h, vector<int>(w, -1));
	rep(i, h)rep(j, w) {
		if (s[i][j] == '#') continue;
		int cnt = 0;
		rep(k, 8) {
			int a = i + dx[k],b = j + dy[k];
			if (a < 0 || b < 0 || a >= h || b >= w) continue;
			if (s[a][b] == '#') cnt++;
		}
		ans[i][j] = cnt;
	}
	rep(i, h) {
		rep(j, w) {
			if (ans[i][j] == -1) cout << "#";
			else cout << ans[i][j];
		}cout << endl;
	}
	return 0;
}