//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 3005
#define MOD 1000000007
ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    string s; cin>>s;
    
    dp[0][1] = 1;
    for(ll i=1;i<N;++i)
    {
        ll pre[i + 1] = {0};
        for(ll j=1;j<=(i + 1);++j)
            pre[j] = (pre[j - 1] + dp[i - 1][j]) % MOD;
        
        for(ll j=1;j<=(i + 1);++j)
        {
            ll L,R;
            if(s[i - 1] == '<')
            {
                L = 1;
                R = j - 1;
            }
            else
            {
                L = j;
                R = i;
            }
            
            if(L <= R)
                dp[i][j] = (pre[R] - pre[L - 1] + MOD) % MOD;
        }
    }
    
    ll ans = 0;
    for(ll i=1;i<=N;++i)
        ans = (ans + dp[N - 1][i]) % MOD;
    
    cout<<ans<<endl;
}