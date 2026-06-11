#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct compare{
    bool operator()(pair<pair<int,int>,ll> a,pair<pair<int,int>,ll> b)
    {
        int x = a.first.first+a.first.second;
        int y = b.first.first+b.first.second;
        return (x)<(y);
    }
};
int n;
int main() {
    priority_queue<pair<pair<int,int>,ll>,vector<pair<pair<int,int>,ll>>,compare> pq;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        pq.push({{a,b},c});
    }
    ll dp[n+1][20005];
    memset(dp,0,sizeof dp);
    int i=1;
    while(!pq.empty())
    {
        pair<pair<int,int>,ll> x = pq.top();
        int w,s;
        ll val;
        w = x.first.first;
        s = x.first.second;
        val = x.second;
        for(int j=w;j<20005;j++)
        {
            int fs = min(s,j-w);
            dp[i][fs] = max(dp[i][fs],dp[i-1][j]+val);
        }
        for(int j=0;j<20005;j++)
        dp[i][j] = max(dp[i][j],dp[i-1][j]);
        pq.pop();
        i++;
    }
    ll ans=0;
    for(int i=0;i<20005;i++)
    ans = max(ans,dp[n][i]);
    cout<<ans;
}