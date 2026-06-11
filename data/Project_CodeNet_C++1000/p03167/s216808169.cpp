#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,k) for(i=0;i<k;i++)
#define ALL(c) (c).begin(),(c).end()
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define SZ(x) (x).size();
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
#define INF 1e18
#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
void solve();

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}


int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	t = 1;

	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}


void solve()
{
	ll n, m, i, j;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m));
	vector<vector<ll>> dp(n, vector<ll>(m, 0));

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cin >> v[i][j];
	}

	for (i = 0; i < n; i++)
	{
		if (v[i][0] == '#')
			break;

		dp[i][0] = 1;
	}

	for (i = 0; i < m; i++)
	{
		if (v[0][i] == '#')
			break;

		dp[0][i] = 1;
	}

	for (i = 1; i < n; i++)
	{
		for (j = 1; j < m; j++)
		{
			if (v[i][j] == '#')
				continue;

			if (dp[i - 1][j] != 0)
				dp[i][j] = dp[i - 1][j] % MOD;

			if (dp[i][j - 1] != 0)
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
		}
	}

	cout << dp[n - 1][m - 1] << endl;



}
