#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define INF INT_MAX
vector<ll> dp;

ll f(vector<ll> &v,ll n)
{
    if(n==0)
    {
        return 0;
    }

    if(n<0)
    {
        return INF;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    ll val1,val2,left,right;
    left=f(v,n-1);
    right=f(v,n-2);
    val1=abs(v[n]-v[n-1]);
    val2=abs(v[n]-v[n-2]);

    if(left==INF&&right==INF)
    {
        return INF;
    }

    if(left==INF)
    {
        return dp[n]=right+val2;
    }

    if(right==INF)
    {
        return dp[n]=left+val1;
    }

    return dp[n]=min(left+val1,right+val2);
}

void solve()
{
    ll n,i,ans;
    cin>>n;
    dp.resize(n,-1);
    vector<ll> v(n);

    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }

    ans=f(v,n-1);
    cout<<ans;
}

int main()
{
    solve();
}
