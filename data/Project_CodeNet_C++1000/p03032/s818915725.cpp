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

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i,n){
        cin >> v[i];
    }
    ll ans=0;
    for(ll l=0;l<=k;l++){
        for(ll r=0;r<=k-l;r++){
            if(r+l>n) break;
            ll d=k-l-r;
            ll now=0;
            vector<ll> s;
            rep(i,l){
                now+=v[i];
                s.push_back(v[i]);
            }
            rep(i,r){
                now+=v[n-1-i];
                s.push_back(v[n-1-i]);
            }
            sort(s.begin(),s.end());
            rep(i,d){
                if(i>=l+r) break;
                if(s[i]>0) break;
                
                now-=s[i];
            }
            ans=max(ans,now);
        }
    }
    cout << ans << endl;
    return 0;
} 