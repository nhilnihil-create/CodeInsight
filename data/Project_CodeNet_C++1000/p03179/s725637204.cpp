#include <bits/stdc++.h>
using namespace std;
typedef int int__;
#define int long long
#define pb push_back
#define pi pair<int,int>
#define vpi vector<pi>
#define vi vector<int>
#define vvi vector<vi>
const int MAX = 1e9 + 7;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
int Mod(int x){const int mm=1e9 + 7;x%=mm;if(x<0)x+=mm;return x;}
int Pow(int x,int n){if(n==0)return 1;int t=Pow(x,n/2);t=Mod(t*t);if(n&1)t=Mod(t*x);return t;}
#define watch(x) cout << #x << " : " << x << endl;
int gcd(int x,int y){return y!=0 ? gcd(y,x%y) : x;}

const int nax = 3005;
const int mod = 1e9 + 7;

int__ main() {
	fast;
	
	int n; cin >> n;
	string a; cin >> a;

	vvi dp(n+1, vi(n+1 , 0));

	dp[1][1] = 1;

	for(int i=2;i<=n;i++) {
		for(int j = 1; j <= n ; j++) {dp[i-1][j] += dp[i-1][j-1]; dp[i-1][j] %= mod;}

		for(int j=1;j<=i;j++) {
			if(a[i-2] == '<') dp[i][j] = Mod(dp[i-1][j-1] - dp[i-1][0]);
			else dp[i][j] = Mod(dp[i-1][n] - dp[i-1][j-1]);
		}
	}

	int ans = 0;

	for(int i=1;i<=n;i++) ans = Mod(ans + dp[n][i]);

	cout << ans << endl;
}
