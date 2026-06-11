#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    pair<int,pair<pair<int,int>,int>> p[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].ss.ff.ff>>p[i].ss.ff.ss>>p[i].ss.ss;
        p[i].ff=(p[i].ss.ff.ff + p[i].ss.ff.ss);
    }
    sort(p,p+n,greater<pair<int,pair<pair<int,int>,int>>>());
    int dp[2][20005];
    memset(dp,0,sizeof(dp));
    int ans=0;
    int c=1;
    for(int i=0;i<n;i++)
    {
        //cout<<p[i].ff<<" "<<p[i].ss.ff.ff<<" "<<p[i].ss.ff.ss<<" "<<p[i].ss.ss<<"\n";
        for(int j=0;j<=10000;j++)
            dp[c][j]=dp[!c][j];
        for(int j=p[i].ss.ff.ff;j<=20000;j++)
        {    
            dp[c][min(j - p[i].ss.ff.ff,p[i].ss.ff.ss)]=max(dp[!c][j] + p[i].ss.ss,dp[c][min(j - p[i].ss.ff.ff,p[i].ss.ff.ss)]) ;
            ans=max(ans ,dp[c][min(j - p[i].ss.ff.ff,p[i].ss.ff.ss)] );
        }
        //cout<<ans<<" \n";
        c^=1;
    }
    cout<<ans;
}