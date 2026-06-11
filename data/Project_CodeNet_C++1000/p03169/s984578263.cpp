#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int const N = 303;

int n;
ld dp[N][N][N];

ld solve(ll a, ll b, ll c)
{
	if (a < 0 || b < 0 || c < 0)
		return 0;

	if (dp[a][b][c] != -1)
		return dp[a][b][c];	

	ld res = (n * 1.0) / ((a + b + c) * 1.0);
	if (a) res += (a * 1.0) / ((a+b+c) * 1.0) * solve(a-1, b, c);
	if (b) res += (b * 1.0) / ((a+b+c) * 1.0) * solve(a+1, b-1, c);
	if (c) res += (c * 1.0) / ((a+b+c) * 1.0) * solve(a, b+1, c-1);

	return dp[a][b][c] = res;
}

int main()
{
	fastio;

	cin >> n;

	int a, b, c;
	a = b = c = 0;

	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;

		if (k == 1) a++;
		else if (k == 2) b++;
		else c++;
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
				dp[i][j][k] = -1;
	dp[0][0][0] = 0;

	cout << fixed << setprecision(15) << solve(a, b, c) << '\n';
	return 0;
}
