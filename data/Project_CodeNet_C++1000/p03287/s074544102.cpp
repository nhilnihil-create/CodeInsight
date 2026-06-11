#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans,a[100005],prfx[100005];
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    for(ll i=1;i<=n;i++)prfx[i]=prfx[i-1]+a[i];
    map<ll,ll> mp;
    mp[0]++;
    for(ll i=1;i<=n;i++){
        ans+=mp[prfx[i]%m];
        mp[prfx[i]%m]++;
    }
    cout<<ans;
}