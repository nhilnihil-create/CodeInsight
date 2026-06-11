#include <bits/stdc++.h>
//#define ll long long
#define int long long
#define pb push_back
#define mod 1000000007;
#define inf (1LL<<60)
using namespace std;


int solve(int h[],int b[],int n)
{
    int dp[n];
    map<int,int> m;
    dp[0]=b[0];
    m[h[0]]=dp[0];
    int ans=dp[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=b[i];
        auto it=m.lower_bound(h[i]);
        if(it!=m.begin())
        {
            it--;
            dp[i]+=it->second;
        }
        m[h[i]]=dp[i];
        it=m.upper_bound(h[i]);
        ans=max(ans,dp[i]);
        while(it!=m.end()&&it->second<=dp[i])
        {
            auto temp =it;
            temp++;
            m.erase(it);
            it=temp;
        }
    }
    return ans;
}
signed main()
{
    int n;
    cin>>n;
    int h[n],b[n];
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<solve(h,b,n);
    return 0;
}
