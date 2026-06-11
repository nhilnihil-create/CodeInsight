#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,k;cin>>n>>k;
    vector< pair<ll,ll> > a(n);
    for(ll i=0;i<n;i++)cin>>a[i].second>>a[i].first;
    sort(a.rbegin(),a.rend());
    ll sum=0,cnt=0,ans=0;
    vector<ll> extra,vis(n+1,0);
    for(ll i=0;i<k;i++){
        sum+=a[i].first;
        if(vis[a[i].second]==0)vis[a[i].second]++,cnt++;
        else vis[a[i].second]++,extra.push_back(i);
    }
    ans = max(ans , sum + cnt*cnt);
    for(ll i=k;i<n;i++){
        if(vis[a[i].second])continue;
        if(extra.size()==0)break;

        ll j = extra.back();
        extra.pop_back();

        vis[a[j].second]--;
        sum-=a[j].first;

        vis[a[i].second]++;
        sum+=a[i].first;
        cnt++;

        ans = max(ans , sum + cnt*cnt);
    }

    cout<<ans;
}