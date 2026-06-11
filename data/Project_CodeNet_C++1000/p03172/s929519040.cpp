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
    
    ll N,K; cin>>N>>K;
    ll arr[N];
    
    for(ll i=0;i<N;++i)
        cin>>arr[i];
    
    ll dp[N + 1][K + 1];
    memset(dp,0,sizeof(dp));
    
    dp[0][0] = 1;
    for(ll i=1;i<=N;++i)
    {
        ll pre[K + 1];
        //cout<<"For i: "<<i<<endl;
        for(ll k=0;k<=K;++k)
        {
            pre[k] = (((k > 0) ? pre[k - 1] : 0) + dp[i - 1][k]) % MOD;
            //cout<<k<<" "<<pre[k]<<endl;
        }
        
        for(ll k=0;k<=K;++k)
            dp[i][k] = (pre[k] - ((k > arr[i - 1]) ? pre[k - arr[i - 1] - 1] : 0) + MOD) % MOD;
    }
    
    //cout<<dp[1][1]<<endl;
    cout<<dp[N][K]<<endl;
}