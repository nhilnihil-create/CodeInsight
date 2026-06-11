#include <bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
#define MP make_pair
#define ld long double
 
using namespace std;
 
const int N = 3e3 + 123;
const ll mod = 1e9 + 7;

int n;
string s;
ll dp[N][N];

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	cin >> s;

	dp[1][1] = 1;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(s[i - 2] == '<'){
				dp[i][j] = dp[i - 1][j - 1];
			}
			else{
				dp[i][j] = (dp[i - 1][i - 1] - dp[i - 1][j - 1] + mod) % mod;
			}
			dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
			//cout << dp[i][j] << " " << i << " " << j << "\n";
		}
	}

	cout << dp[n][n];
	return 0;
}
