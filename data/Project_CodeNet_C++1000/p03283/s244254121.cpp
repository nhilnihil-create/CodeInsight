#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e9+7;

int main(){
    ll n,m,Q;
    cin >> n >> m >> Q;
    vector<ll> l(m),r(m),p(Q),q(Q);
    vector<vector<ll>> d(n);
    rep(i,m){
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
        d[r[i]].push_back(l[i]);
    }
    rep(i,n){
        sort(d[i].begin(),d[i].end());
    }
    rep(i,Q){
        cin >> p[i] >> q[i];
        p[i]--;
        q[i]--;
        ll ans=0;
        for(ll j=p[i];j<=q[i];j++){
            auto it=lower_bound(d[j].begin(),d[j].end(),p[i])-d[j].begin();
            ans+=d[j].size()-it;
        }
        cout << ans << endl;
    }
} 