#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,q,a[2005],ans=(1ll<<30);
bool chk[2005];
ll solve(ll val){
    for(ll i=1;i<=n;i++){
        if(a[i]<val)chk[i]=1;
        else chk[i]=0;
    }
    vector<ll> s,t;
    for(ll i=1;i<=n+1;i++){
        if(chk[i]||i==n+1){
            sort(t.begin(),t.end());
            if(t.size()>=k)for(ll j=0;j<t.size()-(k-1);j++)s.push_back(t[j]);
            t.clear();
        }
        else t.push_back(a[i]);
    }
    sort(s.begin(),s.end());
    if(s.size()<q)return (1ll<<30);
    return s[q-1]-s[0];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>q;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)ans=min(ans,solve(a[i]));
    cout<<ans;
}