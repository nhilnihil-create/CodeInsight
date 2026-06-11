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

int n, a, b, c;
vector<int> v;

int dfs(int i, int x, int y, int z, int s, int t, int u) {
	if (i == n) {
		if (s == 0 || t == 0 || u == 0) return INF;
		else return abs(a-x) + abs(b-y) + abs(c-z) + 10*(s+t+u-3);
	}
	int res = INF;
	res = min(res, dfs(i+1, x + v[i], y, z, s+1, t, u));
	res = min(res, dfs(i+1, x, y + v[i], z, s, t+1, u));
	res = min(res, dfs(i+1, x, y, z + v[i], s, t, u+1));
	res = min(res, dfs(i+1, x, y, z, s, t, u));
	return res;
}

int main() {
	cin >> n >> a >> b >> c;
	v.resize(n);
	rep(i,n) cin >> v[i];
	cout << dfs(0, 0, 0, 0, 0, 0, 0) << endl;
}