#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 300 + 47;
int dp[MAX][MAX][MAX];
string s;

void Max(int& key, int val)
{
	key = max(key, val);
}

int solve(int n, int cnt)
{
	FOR(i, 0, n)
	{
		dp[i][i][0] = 1;
	}

	FOR(len, 2, n + 1)
	{
		FOR(i, 0, n)
		{
			int j = i + len - 1;
			if (j >= n) break;
			FOR(k, 0, cnt + 1)
			{
				if (s[i] == s[j])
				{
					Max(dp[i][j][k], dp[i + 1][j - 1][k] + 2);
				}

				if (k) Max(dp[i][j][k], dp[i + 1][j - 1][k - 1] + 2);
				Max(dp[i][j][k], dp[i][j - 1][k]);
				Max(dp[i][j][k], dp[i + 1][j][k]);
			}
		}
	}

//	FOR(i, 0, n)
//	{
//		FOR(j, i, n)
//		{
//			FOR(k, 0, cnt + 1)
//			{
//				cout << i << " " << j << " " << k << ": " << dp[i][j][k] << endl;
//			}
//		}
//	}
	int ans = 0;
	FOR(k, 0, cnt + 1) Max(ans, dp[0][n - 1][k]);
	return ans;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(0);
	int k, n;
	cin >> s >> k;
	n = SZ(s);
	int ans = solve(n, k);
	cout << ans << endl;
	return 0;
}
