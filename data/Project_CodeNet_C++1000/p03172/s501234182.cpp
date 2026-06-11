#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 10000000000099ll
#define mod 1000000007
#define prDouble(x) cout<<fixed<<setprecision(10)<<x

ll solve(vector<int>& v, int n, int k)
{
    ll dp[n+2][k+2];
    for(int i=0; i<=k; i++)
        dp[1][i]= (i>v[1]) ? 0 : 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(j==0)
                dp[i][j]= dp[i-1][j];
            else dp[i][j]= (mod + dp[i][j-1] + dp[i-1][j] - ((j-v[i]-1 >=0) ? dp[i-1][j-v[i]-1] : 0))%mod;
        }
    }
    return dp[n][k]%mod;
}

int main()
{
    FASTIO;
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    loop(i,1,n+1) cin>>v[i];
    cout<<solve(v, n, k);
    return 0;
}

