#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,k;
    long long rm=1e9+7;
    cin>>n>>k;
    vector<long long>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    vector<vector<long long> > dp(n+1,vector<long long>(k+1));
    for(int i=0;i<=v[0];i++){
        dp[1][i]=1ll;
    }
    long long ttl=v[0];
    for(int in=2;in<=n;in++){
        ttl+=v[in-1];
        for(int ik=0;ik<=k;ik++){
            if(ik==0){
                dp[in][ik]=1ll;
                continue;
            }
            if(ik>v[in-1])
                dp[in][ik]=dp[in-1][ik]+dp[in][ik-1]-dp[in-1][ik-v[in-1]-1];
            else{
                dp[in][ik]=dp[in][ik-1]+dp[in-1][ik];
            }
            dp[in][ik]%=rm;
            dp[in][ik]+=rm;
            dp[in][ik]%=rm;
            if(ik>ttl)
                break;
        }
    }
    cout<<dp[n][k]<<'\n';

/**
5
0.42 0.01 0.42 0.99 0.42
*/
    return 0;
}
