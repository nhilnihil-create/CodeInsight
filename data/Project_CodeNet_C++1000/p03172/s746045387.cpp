#include <vector>
#include <iostream>
#include <math.h>

using namespace std;
typedef long long int ll;
ll MOD = pow(10,9) + 7;

ll solve(vector<ll>& kids,ll K)
{
    ll n = kids.size();

    vector<vector<ll>> dp(n+1,vector<ll>(K+1));
    vector<ll> rs(K+1,1);
    vector<ll> nex_rs(K+1);
    nex_rs[0] = 1;

    for (int i=0;i<=n;++i)
    {
        dp[i][0] = 1;
    }

    for (int i=1;i<=n;++i)
    {
        //cout<<"KIDS:"<<i<<endl;
        //for (auto i:rs) cout<<i<<" ";
        
        vector<ll> rs(K+1);
        rs[0] = 1;
        for (int x=1;x<=K;++x)
        {
            rs[x] = rs[x-1] + dp[i-1][x];
        }
        
        for (int can=1;can<=K;++can)
        {
            /**
            if (can < i)
            {
                nex_rs[can]  = 1;
                continue;
            }
            **/

            //cout<<endl;

            ll upto = can - kids[i-1] - 1;
            dp[i][can] = rs[can];
            
            if (upto>=0) dp[i][can] -= rs[upto];
            dp[i][can] %= MOD;
            //nex_rs[can] = (nex_rs[can-1] + dp[i][can]) % MOD;
        }

        //rs = nex_rs;
    }
    /**
    for (auto v:dp)
    {
        for (auto i:v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    **/
    return dp[n][K];
}

int main()
{
    int N,K;
    cin>>N>>K;
    vector<ll> kids(N);

    for (int i=0;i<N;++i)
    {
        cin>>kids[i];
    }

    cout<<solve(kids,K)<<endl;

    return 0;
}
