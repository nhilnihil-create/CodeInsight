#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3")
//#pragma GCC target("sse4")

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = (LL)INF * INF;

const int MAX = 5007;

LL dp[MAX][MAX];
int p[MAX];

void upd(LL& x, LL val)
{
	x = min(x, val);
}

int main()
{
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	FOR(i, 1, n + 1)
		cin >> p[i];
	FOR(i, 0, n + 1)
		FOR(j, 0, n + 1)
			dp[i][j] = LINF;
	dp[0][0] = 0;
	FOR(i, 0, n)
		FOR(j, 0, i + 1)
		{
			if(p[i + 1] > p[j])
				upd(dp[i + 1][i + 1], dp[i][j]);
			upd(dp[i + 1][j], dp[i][j] + (p[i + 1] > p[j] ? a : b));
		}
	LL ans = LINF;
	FOR(j, 0, n + 1)
		upd(ans, dp[n][j]);
	cout << ans;
	return 0;
}