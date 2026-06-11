#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

const int NUM = 10;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> f(n, vector<int>(NUM)), p(n, vector<int>(NUM+1));
	rep(i,n) rep(j,NUM) cin >> f[i][j];
	rep(i,n) rep(j,NUM+1) cin >> p[i][j];
	ll ans = -LINF;
	for (int bit = 1; bit < (1 << NUM); bit++) {
		ll t = 0;
		for (int k = 0; k < n; k++) {
			int c = 0;
			for (int i = 0; i < NUM; i++) {
				if ((bit & (1 << i)) && f[k][i]) c++;
			}
			t += p[k][c];
		}
		ans = max(ans, t);
	}
	cout << ans << endl;
}