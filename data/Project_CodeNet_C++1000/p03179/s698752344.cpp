#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0);cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define forn(i,a,n) for(int i=a; i < n; i++)
typedef long long int lli;
typedef long double Double;
typedef pair<int,int> pii;
typedef vector<lli> vi;
typedef vector<vi> vvi;
#define MAXN 3005
const int mod = 1e9+7;
lli dp[MAXN][MAXN];
int main(){__
	int n;
	cin >> n;
	dp[0][1] = 1ll;
	for(int i =1; i < n; i++){
		char c;
		cin >> c;
		if(c == '>'){
			lli sum = 0ll;
			for(int j = i+1; j >=1; j--){
				sum = (sum + dp[i-1][j]) % mod;
				dp[i][j] = (dp[i][j] + sum) % mod;
			}
			/*
			for(int j =1; j <=i+1; j++){
				for(int k = i+1; k >= j; k--){
					dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
				}
			}
			*/
		}
		else{
			lli sum = 0ll;
			for(int j =1; j <= i+1; j++){
				dp[i][j] = (dp[i][j] + sum) % mod;
				sum = (sum + dp[i-1][j]) % mod;
			}
			/*
			for(int j=1; j <=i+1; j++){
				for(int k= 1; k < j; k++){
					dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
				}
			}
			*/
		}
	}

	lli ans = 0ll;
	for(int i =1; i <= n; i++){
		ans = (ans + dp[n-1][i]) % mod;
	}
	cout << ans % mod << endl;
	return 0;
}
