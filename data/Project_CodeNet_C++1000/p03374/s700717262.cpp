#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<set>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };
#define MOD 1000000007
#define ARRAY_MAX 100015

//const int INF = 1e9 + 7;


ll dp[2][ARRAY_MAX];

int main() {

	ll n, c;
	cin >> n >> c;

	vector<ll> x(ARRAY_MAX,0), v(ARRAY_MAX,0);

	for (int i = 1; i <= n; i++)
	{
		cin >> x[i] >> v[i];
	}
	x[0] = 0;
	x[n + 1] = c;

	ll cal = 0;
	for (int i = 1; i <= n; i++)
	{
		//時計回り方向の累積和
		dp[0][i] = dp[0][i - 1] + v[i] - (x[i] - x[i - 1]);
	}

	for (int i = 1; i <= n; i++)
	{
		//反時計回り方向のi番目までのカロリーの最大
		dp[0][i] = max(dp[0][i], dp[0][i-1]);
	}
	
	cal = 0;
	for (int i = n; i >= 1; i--)
	{
		//反時計回り方向の累積和
		dp[1][i] = dp[1][i + 1] + v[i] - (x[i + 1] - x[i]);
	}

	for (int i = n; i >= 1; i--)
	{
		//反時計回り方向のi番目までのカロリーの最大
		dp[1][i] = max(dp[1][i], dp[1][i + 1]);
	}

	ll maxi = 0;

	for (int i = 0; i <= n; i++)
	{
		//時計周りスタート
		maxi = max(maxi, dp[0][i] + dp[1][i + 1] - x[i]);

		//反時計回りスタート
		maxi = max(maxi, dp[0][i] + dp[1][i + 1] - (c - x[i + 1]));
	}
	cout << maxi << endl;

	return 0;
}
