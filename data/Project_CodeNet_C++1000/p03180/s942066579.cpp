//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MINN -1e18
#define MAXN 3005
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    ll arr[N][N];
    
    vector<ll> dp((1 << N),MINN);
    ll cost[1 << N];
    
    for(ll i=0;i<N;++i)
    {
        for(ll j=0;j<N;++j)
        {
            cin>>arr[i][j];
        }
    }
    
    for(ll mask=0;mask < (1 << N);++mask)
    {
        ll ans = 0;
        for(ll i=0;i<N;++i)
        {
            if(mask & (1 << i))
            {
                for(ll j=(i + 1);j<N;++j)
                {
                    if(mask & (1 << j))
                        ans += arr[i][j];
                }
            }
        }
        
        cost[mask] = ans;
        //cout<<mask<<" "<<cost[mask]<<endl;
    }
    

    
    dp[0] = 0;
    for(ll mask=1;mask < (1 << N);++mask)
    {
        ll submask = mask;
        while(submask)
        {
            ll rem = mask ^ submask;
            dp[mask] = max(dp[mask],dp[rem] + cost[submask]);
            
            submask = (submask - 1) & mask;
        }
    }
    
    cout<<dp[(1 << N) - 1]<<endl;
}