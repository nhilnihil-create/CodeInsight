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
    ll n,m;
    cin >> n >> m;
    vector<ll> s(n+1);
    map<ll,ll> h;
    s[0]=0;
    h[0]++;
    rep(i,n){
        ll a;
        cin >> a;
        s[i+1]=(s[i]+a)%m;
        h[s[i+1]]++;
    }
    ll ans=0;
    for(auto x:h){
        if(x.se>=2){
            ans+=(x.se-1)*x.se/2;
        }
    }
    cout << ans << endl;
    return 0;
}
