#include<bits/stdc++.h>
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

#define F first
#define S second
#define pb push_back
#define int long long
#define maxn 200000
#define mod 1000000007
#define inf 1000000000000000000

#define fr(i,a,b) for(int i=a;i<b;i++)
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
#define all(x) begin(x), end(x)
#define PII pair<int, int>
#define VI vector<int>
#define VII vector<PII>

using namespace std;

int n, dp[3001][3001], pref_sum[3001];
string s;

signed main()
{
    FLASH

    cin>>n>>s;
    dp[1][1] = 1;
    fr(j, 1, n + 1) pref_sum[j] = pref_sum[j  - 1] + dp[1][j];

    fr(i, 2, n + 1){
    	fr(j, 1, i + 1){
    		if(s[i - 2] == '<'){
    			dp[i][j] = pref_sum[j - 1];
    		}
    		else dp[i][j] = pref_sum[i] + mod - pref_sum[j - 1];
    		dp[i][j] %= mod;
    	}
    	fr(j, 1, n + 1) pref_sum[j] = (pref_sum[j - 1] + dp[i][j])%mod;
    }

    int ans = 0;
    fr(j, 1, n + 1) ans += dp[n][j], ans %= mod;
    cout<<ans<<'\n';
}