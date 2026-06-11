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

	vi dis0(c, 0), dis1(c, 0), dis2(c, 0);

	rep(k, c)rep(i, n)rep(j, n)if ((i + j) % 3 == 0)dis0[k] += d[cc[i][j]][k];
	rep(k, c)rep(i, n)rep(j, n)if ((i + j) % 3 == 1)dis1[k] += d[cc[i][j]][k];
	rep(k, c)rep(i, n)rep(j, n)if ((i + j) % 3 == 2)dis2[k] += d[cc[i][j]][k];

	int ans = INF;

	rep(i, c)rep(j, c)rep(k, c) {
		if (i == j || j == k || k == i)continue;
		ans = min(ans, dis0[i] + dis1[j] + dis2[k]);
	}

	cout << ans << endl;
}