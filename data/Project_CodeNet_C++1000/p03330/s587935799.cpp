#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()

constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;

int main() {

	int n, c;
	cin >> n >> c;
	vvi d(c, vi(c));
	rep(i, c)rep(j, c)cin >> d[i][j];
	vvi cc(n, vi(n));
	rep(i, n)rep(j, n) { cin >> cc[i][j]; cc[i][j]--; }


	vvi dis(3, vi(c, 0));

	rep(l,3)rep(k, c)rep(i, n)rep(j, n)if ((i + j) % 3 == l)dis[l][k] += d[cc[i][j]][k];
	int ans = INF;

	rep(i, c)rep(j, c)rep(k, c) {
		if (i == j || j == k || k == i)continue;
		ans = min(ans, dis[0][i] + dis[1][j] + dis[2][k]);
	}

	cout << ans << endl;
}