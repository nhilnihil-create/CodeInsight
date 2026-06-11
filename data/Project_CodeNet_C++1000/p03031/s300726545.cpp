#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int func(vector<vector<int>> v, int n, int m, vector<int> p) {
	int res = 0;
	rep(bit, (1 << n)) {
		bool b = true;
		rep(i,m) {
			vector<int> u = v[i];
			int temp = 0;
			for (int j: u) {
				if ((bit & (1 << j))) temp++;
			}
			if (!(temp % 2 == p[i])) b = false;
		}
		if (b) res++;
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(m);
	rep(i,m) {
		int k;
		cin >> k;
		v[i].resize(k);
		rep(j,k) {
			cin >> v[i][j];
			v[i][j]--;
		}
	}
	vector<int> p(m);
	rep(i,m) cin >> p[i];
	int ans = func(v, n, m, p);
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}