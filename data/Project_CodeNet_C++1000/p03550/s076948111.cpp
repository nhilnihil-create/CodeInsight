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
    ll n,z,w;
    cin >> n >> z >> w;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<ll> dp1(n);
    vector<ll> dp2(n,INF);
    for(ll i=n-1;i>=0;i--){
        if(i==0){
            dp1[i]=max(dp1[i],abs(a[n-1]-w));
        }
        else{
            dp1[i]=max(dp1[i],abs(a[n-1]-a[i-1]));
            dp2[i]=min(dp2[i],abs(a[n-1]-a[i-1]));
        }
        for(ll j=n-1;j>=i+1;j--){
            dp1[i]=max(dp1[i],dp2[j]);
            dp2[i]=min(dp2[i],dp1[j]);
        }
    }
    cout << dp1[0] << endl;
    return 0;
}