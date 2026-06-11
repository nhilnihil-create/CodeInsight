#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;
typedef long long int ll;

ll solve(vector<ll>& v)
{
    ll n = v.size();
    vector<vector<ll>> dp(n,vector<ll>(n,0));

    vector<ll> sum(n);

    sum[0] = v[0];
    for (ll i=1;i<n;++i)
    {
        sum[i] = sum[i-1] + v[i];
    }

    //f/or (auto i:sum) cout<<i<<" ";
    //cout<<endl;

    for (ll i=0;i<n-1;++i)
    {
        dp[i][i+1] = v[i] + v[i+1];
    }

    for (ll s=3;s<=n;++s)
    {
        ll lim = n - s;
        for (ll i=0;i<=lim;++i)
        {
            ll k = i + s - 1;

            ll M = INFINITY;
            ll range_sum = sum[k];
            if (i>0) range_sum -= sum[i-1];
            //cout<<i<<" "<<k<<" "<<range_sum<<"####"<<endl;

            for (ll j=i;j<=k-1;++j)
            {
                //cout<<dp[i][j]<<"A"<<j<<" "<<i<<" "<<s<<endl;
                //cout<<dp[j+1][k]<<"B"<<endl;
                ll cand = dp[i][j] + dp[j+1][k] + sum[k];
                if (i>0) cand -= sum[i-1];

                //cout<<cand<<"CAAA"<<endl;

                M = min(M,cand);
            }

            dp[i][k] = M;

        }

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
    return dp[0][n-1];
}

int main()
{
    ll N;
    cin>>N;

    vector<ll> v(N);

    for (ll i=0;i<N;++i)
    {
        cin>>v[i];
    }

    cout<<solve(v)<<endl;

    return 0;
}
