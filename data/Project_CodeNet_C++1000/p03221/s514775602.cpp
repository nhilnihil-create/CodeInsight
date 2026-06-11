#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> v(n);
    ll p,y;
    rep(i,m){
        cin>>p>>y;
        p--;
        v[p].push_back(make_pair(y,i));
    }
    rep(i,n) sort(all(v[i]));
    vector<pair<ll,ll>> mp(m);
    rep(i,n){
        rep(j,v[i].size()){
            mp[v[i][j].second]=make_pair(i+1,j+1);
        }
    }
    rep(i,m) printf("%06ld%06ld\n",mp[i].first,mp[i].second);
    return 0;
}