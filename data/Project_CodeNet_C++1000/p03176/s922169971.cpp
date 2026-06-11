#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
 int n;
    cin>>n;
    int base=1;
    while(base<=n)
    {
        base*=2;
    }
    vector<ll> tree (2*base);
    vector<int> h(n),a(n);
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<ll> dp(n+1);
    for(int flower=0;flower<n;flower++)
    {
        int x=h[flower]+base;
        ll best=0;
        while(x>1)
        {
            if(x%2==1)
            {
                best=max(best,tree[x-1]);
            }
            x/=2;
        }
        dp[h[flower]]=best+a[flower];
        for(int i=base+h[flower];i>=1;i/=2)
        {
            tree[i]=max(tree[i],dp[h[flower]]);
        }
    }
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}