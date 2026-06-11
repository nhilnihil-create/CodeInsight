#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int lli;
const lli N=1e3+5;
vector<pair<pair<lli,lli>,lli>> v;
lli dp[20005];

bool cmp(const pair<pair<lli,lli>,lli> &a,const pair<pair<lli,lli>,lli> &b)
{
    return a.first.first+a.first.second < b.first.first+b.first.second;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    lli n;
    cin>>n;
    lli i,j,ans=0,w,s,va;
    
    for(i=0;i<n;i++) 
    {
        cin>>w>>s>>va;
        v.push_back({{w,s},va});
    }
    sort(v.begin(), v.end(), cmp);
    
    for(i=0;i<n;i++)
    {
        for(j=v[i].first.second;j>=0;j--)
        {
            dp[j+v[i].first.first]=max(dp[j+v[i].first.first], dp[j]+v[i].second);
        }
    }
    
    for(i=0;i<20005;i++) ans=max(ans, dp[i]);
    cout<<ans;
    return 0;
}