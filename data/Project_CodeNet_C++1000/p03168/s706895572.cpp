using namespace std;
#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#define w(x) int x;cin>>x;while(x--)

#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define ll long long

void abc()
{
	FIO;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int mod = 1000000007;
vector<double> v;
vector<vector<double>> dp;
int n;







int main()
{
	abc();

	cin >> n;
	v.resize(n);
	dp.resize(n + 1, vector<double>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {

			if (j == 0) {
				dp[i][j] = (1 - v[i - 1]) * dp[i - 1][j];
			} else {
				dp[i][j] = (v[i - 1]) * dp[i - 1][j - 1] + (1 - v[i - 1]) * dp[i - 1][j];
			}

		}
	}

	double ans = 0;

	for (int i = (n / 2) + 1; i <= n; i++) {

		ans += dp[n][i];
	}

	cout << setprecision(10) << ans;



}