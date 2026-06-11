#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int n, m;
V<ll> x, y, z;

vi xs = { -1,-1,-1,-1, 1, 1, 1, 1 };
vi ys = { -1,-1, 1, 1,-1,-1, 1, 1 };
vi zs = { -1, 1,-1, 1,-1, 1,-1, 1 };
ll memo[1020][1020][8];

ll dp(int i, int j, int s) {
	if (memo[i][j][s] != -LINF)return memo[i][j][s];
	if (i == 0 || j == 0)return 0;
	if (i < j)return -LINF;
	ll eat = x[i-1] * xs[s] + y[i-1] * ys[s] + z[i-1] * zs[s];
	ll re;
	if (i > j)re = max(dp(i - 1, j - 1, s) + eat, dp(i - 1, j, s));
	else re = dp(i - 1, j - 1, s) + eat;

	memo[i][j][s] = re;
	return re;
}

int main() {


	cin >> n >> m;
	x.resize(n);
	y.resize(n);
	z.resize(n);
	rep(i, n)cin >> x[i] >> y[i] >> z[i];
	rep(i, n + 1)rep(j, m + 1)rep(k, 8)memo[i][j][k] = -LINF;


	ll ans = -LINF;

	rep(i, 8)ans = max(ans, dp(n, m, i));
	cout << ans << endl;

}