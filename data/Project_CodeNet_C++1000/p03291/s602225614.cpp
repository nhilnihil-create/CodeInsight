#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 2001005;

void go() {
	string s;
	cin >> s;
	int n = s.size();
	s = " " + s;
	ll dp[n + 5][3] = {};
	ll mul = 1;
	f1(n) {
		if (s[i] == 'A') {
			(dp[i][0] = dp[i - 1][0] + mul) % mod;
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 1][2];
		}
		if (s[i] == 'B') {
			dp[i][1] = (dp[i - 1][1] + dp[i - 1][0]) % mod;
			dp[i][0] = dp[i - 1][0];
			dp[i][2] = dp[i - 1][2];
		}
		if (s[i] == 'C') {
			dp[i][2] = (dp[i - 1][2] + dp[i - 1][1]) % mod;
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
		}
		if (s[i] == '?') {
			dp[i][0] = (dp[i - 1][0] * 3 + mul) % mod;
			dp[i][1] = (dp[i - 1][1] * 3 + dp[i - 1][0]) % mod;
			dp[i][2] = (dp[i - 1][2] * 3 + dp[i - 1][1]) % mod;
			mul *= 3;
			mul %= mod;
		}
	}
	cout << dp[n][2] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        go();
    }
    
}