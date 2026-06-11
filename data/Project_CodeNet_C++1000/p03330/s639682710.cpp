#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,c;cin>>n>>c;
    ll d[c][c];for(ll i=0;i<c;i++)for(ll j=0;j<c;j++)cin>>d[i][j];
    ll a[n][n];for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)cin>>a[i][j],a[i][j]--;
    map< ll , map<ll,ll> > mp;
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)mp[(i+j)%3][a[i][j]]++;
    ll ans = 1e16;
    for(ll i=0;i<c;i++){
        for(ll j=0;j<c;j++){
            for(ll k=0;k<c;k++){
                if(i==j || j==k || i==k)continue;
                ll cur = 0;
                for(auto &ele:mp[0])cur = cur + ele.second*d[ele.first][i];
                for(auto &ele:mp[1])cur = cur + ele.second*d[ele.first][j];
                for(auto &ele:mp[2])cur = cur + ele.second*d[ele.first][k];
                ans=min(ans,cur);
            }
        }
    }
    cout<<ans;
}