//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXX 1e12
#define MAXN 100005
#define MOD 1000000007
bool dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N,K; cin>>N>>K;
    
    ll arr[N];
    for(ll i=0;i<N;++i)
    {
        cin>>arr[i];
    }
    
    for(ll i=1;i<=K;++i)
    {
        ll flag = 0;
        for(ll j=0;j<N;++j)
        {
            if(i >= arr[j] && !dp[i - arr[j]])
            {
                flag = 1;
                break;
            }
        }
        
        if(flag)
            dp[i] = 1;
    }
    
    
    if(dp[K])
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;
}