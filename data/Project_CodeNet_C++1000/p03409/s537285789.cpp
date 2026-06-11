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

const ll mod=1e9+7;

int main(){
    ll n;
    cin >> n;
    vector<pll> a(n),c(n);
    vector<ll> d(n);
    
    rep(i,n){
        cin >> a[i].fi >> a[i].se;
    }
    rep(i,n){
        cin >> c[i].fi >> c[i].se;
    }
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    ll ans=0;
    rep(i,n){
        ll x=-1,y=-1,num=-1;
        rep(j,n){
            if(c[i].fi>a[j].fi && c[i].se>a[j].se && d[j]==0){
                if(a[j].se>=y){
                    x=a[j].fi;
                    y=a[j].se;
                    num=j;
                }
            }
        }
        if(num==-1) continue;
        d[num]=1;
        ans++;
    }
    cout << ans << endl;
} 