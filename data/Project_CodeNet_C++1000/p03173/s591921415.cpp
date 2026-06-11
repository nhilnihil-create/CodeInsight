//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    ll arr[N];
    ll pre[N];
    ll MAXX = 1e18;
    ll dp[N][N];
    
    for(ll i=0;i<N;++i)
    {
        cin>>arr[i];
        pre[i] = ((i > 0) ? pre[i - 1] : 0) + arr[i];
    }
    
    for(ll diff=0;diff<N;++diff)
    {
        for(ll i=0;i<N;++i)
        {
            ll j = i + diff;
            if(j >= N)
                continue;
            
            dp[i][j] = MAXX;
            
            if(diff == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            
            for(ll k=i;k<j;++k)
            {
                ll one = pre[j];
                ll two = ((i > 0) ? pre[i - 1] : 0);
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j] + one - two);
            }
        }
    }
    
    cout<<dp[0][N - 1]<<endl;
}