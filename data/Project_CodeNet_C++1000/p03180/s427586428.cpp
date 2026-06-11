#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<vector<ll>> v(16,vector<ll>(16));
vector<ll> sop((1<<16)-1,-1);
vector<ll> dp1((1<<16)-1,-1);
ll solve(int s)
{
    if(s==0)
    return 0;
    ll ans=0;
    for(int m=s;m!=0;m=((m-1)&s))
    {
        // cout<<m<<" "<<dp[m]<<"\n";
        if(dp1[(~m)&s]!=-1)
        ans = max(ans,sop[m]+dp1[(~m)&s]);
        else
        ans = max(ans,sop[m]+solve((~m)&s));
    }
    return dp1[s] = ans;
}
int main() {
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>v[i][j];
        }
    }
    for(int k=1;k<(1<<n);k++)
    {
        ll ans=0;
        for(int i=0;i<16;i++)
        {
            for(int j=i+1;j<16;j++)
            {
                if(((1<<i)&k)&&((1<<j)&k))
                ans+=v[i][j];
            }
        }
        sop[k]=ans;
    }
    cout<<solve((1<<n)-1);
}
