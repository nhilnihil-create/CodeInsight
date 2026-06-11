#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct flower{
   ll h,b;
};
int main() {
    int n;
    cin>>n;
    vector<flower> v(n);
    vector<ll> dp(n);
    for(int i=0;i<n;i++)
    cin>>v[i].h;
    for(int i=0;i<n;i++)
    cin>>v[i].b;
    ll ans = v[0].b;
    dp[0] = v[0].b;
    map<ll,ll> mp;
    mp[v[0].h] = v[0].b;
    for(int i=1;i<n;i++)
    {
        dp[i] = v[i].b;
        // cout<<dp[i];
        auto it = mp.upper_bound(v[i].h);
        if(it!=mp.begin())
        {
           --it;
           dp[i]+=(*it).second;
        }
        mp[v[i].h] = dp[i];
        it = mp.upper_bound(v[i].h);
        while(it!=mp.end()&&((*it).second<=dp[i]))
        {
            auto tem = it;
            tem++;
            mp.erase(it);
            it = tem;
        }
        ans = max(ans,dp[i]);
    }
    cout<<ans;
}
