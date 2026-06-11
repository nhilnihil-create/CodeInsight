#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> d(10, vector<int>(10));
	rep(i,10) rep(j,10) cin >> d[i][j];
	vector<vector<int>> v(h, vector<int>(w));
	rep(i,h) rep(j,w) cin >> v[i][j];
	for (int k = 0; k < 10; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = 0;
	rep(i,h) rep(j,w) {
		if (v[i][j] == -1) continue;
		ans += d[v[i][j]][1];
	}
	cout << ans << endl;
}