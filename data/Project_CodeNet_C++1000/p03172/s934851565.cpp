#include <bits/stdc++.h>
 
using namespace std;

typedef long long lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vi;
typedef vector<vector<lli> > vvi;
typedef vector<ii> vii;

#define EB emplace_back
#define PB push_back
#define MP make_pair
#define FF first
#define SS second

lli mod = 1e9 +7;
lli dp[100001], presum[100001], a[100002], n, k;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=k+1; i++)presum[i]=1;
    for(int i=1; i<=n; i++)
    {
    	for(lli j=0; j<=k; j++)
    		dp[j] = (presum[j+1] - presum[max(0LL, j-a[i])] + 2*mod)%mod;
    	for(int x=1; x<=k+1; x++)
    		presum[x] = (presum[x-1]+dp[x-1])%mod;
    	// cout << "\n";
    }
    cout << dp[k];
}