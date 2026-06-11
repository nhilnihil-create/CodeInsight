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
    ll n,k;
    cin >> n >> k;
    vector<ll> p,q;
    rep(i,n){
        ll x;
        cin >> x;
        if(x>=0) p.push_back(x);
        else q.push_back(-x);
    }
    sort(p.begin(),p.end());
    sort(q.begin(),q.end());
    ll r=p.size();
    ll s=q.size();
    ll ans=INF;
    rep(i,r){
        if(0<=k-i-2 && k-i-2<=s-1){
            ans=min(ans,p[i]*2+q[k-i-2]);
        }
        if(i==k-1){
            ans=min(ans,p[i]);
        }
    }
    rep(i,s){
        if(0<=k-i-2 && k-i-2<=r-1){
            ans=min(ans,q[i]*2+p[k-i-2]);
        }
        if(i==k-1){
            ans=min(ans,q[i]);
        }
    }
    cout << ans << endl;
    return 0;
} 
