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
	ll h[n + 1];
	for(ll i = 1; i <= n; i++) {
		cin >> h[i];
	}
	ll dp[n + 1] = {0};
	dp[1] = 0;
	dp[2] = abs(h[2] - h[1]);
	for(ll i = 3; i <= n; i++) {
		dp[i] = min((abs(h[i] - h[i - 1]) + dp[i - 1]), (abs(h[i] - h[i - 2]) + dp[i - 2]));
	}
	cout << dp[n];
 	return 0;
}
