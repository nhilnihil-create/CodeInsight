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

const ll INF=1e18;

int main()
{
    ll a,b,q;
    cin >> a >> b >> q;
    vector<pll> s(a),t(b);
    rep(i,a){
        cin >> s[i].fi;
    }
    rep(i,b){
        cin >> t[i].fi;
    }
    rep(i,a){
        auto it=lower_bound(t.begin(),t.end(),make_pair(s[i].fi,s[i].se))-t.begin();
        ll v=abs(t[it].fi-s[i].fi);
        if(it!=0) v=min(v,abs(t[it-1].fi-s[i].fi));
        s[i].se=v;
    }
    rep(i,b){
        auto it=lower_bound(s.begin(),s.end(),make_pair(t[i].fi,t[i].se))-s.begin();
        ll v=abs(s[it].fi-t[i].fi);
        if(it!=0) v=min(v,abs(s[it-1].fi-t[i].fi));
        t[i].se=v;
    }
    rep(i,q){
        ll x;
        cin >> x;
        ll ans=INF;
        auto it1=lower_bound(s.begin(),s.end(),make_pair(x,0LL))-s.begin();
        auto it2=lower_bound(t.begin(),t.end(),make_pair(x,0LL))-t.begin();
        if(it1!=a){
            ans=min(ans,abs(x-s[it1].fi)+s[it1].se);
        }
        if(it2!=b){
            ans=min(ans,abs(x-t[it2].fi)+t[it2].se);
        }
        if(it1!=0){
            ans=min(ans,abs(x-s[it1-1].fi)+s[it1-1].se);
        }
        if(it2!=0){
            ans=min(ans,abs(x-t[it2-1].fi)+t[it2-1].se);
        }
        cout << ans << endl;
    }
    return 0;
} 