#include<bits/stdc++.h>
#define ll long long int
#define INF 1000000000
#define mod 1000000007
#define endl "\n"
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int main()
{
	fio
	ll n;
	cin >> n;
	ll a, b, c;
	ll dp[n + 1][3];
	cin >> a >> b >> c;
	dp[1][1] = a;
	dp[1][2] = b;
	dp[1][3] = c;
	for(ll i = 2; i <= n; i++) {
		cin >> a >> b >> c;
		dp[i][1] = a + max(dp[i - 1][2], dp[i - 1][3]);
		dp[i][2] = b + max(dp[i - 1][1], dp[i - 1][3]);
		dp[i][3] = c + max(dp[i - 1][1], dp[i - 1][2]);
	}
	cout << max(max(dp[n][1], dp[n][2]), dp[n][3]);
 	return 0;
}
