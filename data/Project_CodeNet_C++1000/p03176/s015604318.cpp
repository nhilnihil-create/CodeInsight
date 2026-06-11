#include <bits/stdc++.h>
#define pb push_back
#define int long long 
#define f(i,a,b) for (int i= a; i <b; ++i)
using namespace std;
int solve(int h[],int b[],int n)
{
    int dp[n];
    dp[0]=b[0];
    map<int,int> m;
    m[h[0]]=dp[0];
    int ans=b[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=b[i];
        auto it=m.upper_bound(h[i]);
        if(it!=m.begin())
        {
            it--;
            dp[i]+=it->second;
        }
        m[h[i]]=dp[i];
        ans=max(ans,dp[i]);
        it=m.upper_bound(h[i]);
        while(it!=m.end()&&it->second<=dp[i])
        {
            auto temp=it;
            temp++;
            m.erase(it);
            it=temp;
        }
    }
    return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int h[n],b[n];
    for(int i=0;i<n;i++)
        cin>>h[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<solve(h,b,n);
}

