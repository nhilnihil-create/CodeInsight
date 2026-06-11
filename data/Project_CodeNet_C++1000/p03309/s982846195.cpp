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
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        a[i]-=i+1;
    }
    sort(a.begin(),a.end());
    if(n%2==1){
        ll m=a[n/2];
        ll ans=0;
        rep(i,n){
            ans+=abs(a[i]-m);
        }
        cout << ans << endl;
    }
    else{
        ll m1=a[n/2-1];
        ll m2=a[n/2];
        ll ans1=0,ans2=0;
        rep(i,n){
            ans1+=abs(a[i]-m1);
        }
        rep(i,n){
            ans2+=abs(a[i]-m2);
        }
        cout << min(ans1,ans2) << endl;
    }
    return 0;
} 