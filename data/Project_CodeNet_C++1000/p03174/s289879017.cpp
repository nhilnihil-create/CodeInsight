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
    ll arr[N][N];
    ll dp[1LL << N];
    
    for(ll i=0;i<N;++i)   
    {
        for(ll j=0;j<N;++j)
        {
            cin>>arr[i][j];
        }
    }
    
    dp[0] = 1; //base case
    for(ll mask = 1;mask < (1 << N);++mask)
    {
        dp[mask] = 0;
        ll male_no = __builtin_popcount(mask);
        male_no--;
        
        for(ll j=0;j<N;++j)
        {
            if(arr[male_no][j] && (mask & (1LL << j)))
            {
                dp[mask] += dp[mask ^ (1LL << j)];
                dp[mask] %= MOD;
            }
        }
    }
    
    cout<<dp[(1LL << N) - 1]<<endl;
}