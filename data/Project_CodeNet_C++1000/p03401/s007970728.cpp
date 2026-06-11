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

const ll INF=1LL<<31;

int main(){
    ll n;
    cin >> n;
    ll sum=0;
    vector<ll> a(n+2);
    rep(i,n){
        cin >> a[i+1];
    }
    for(ll i=1;i<=n+1;i++){
        sum+=abs(a[i]-a[i-1]);
    }
    for(ll i=1;i<=n;i++){
        if(a[i-1]<=a[i] && a[i]<=a[i+1]){
            cout << sum << endl;
            continue;
        }
        if(a[i-1]<=a[i+1] && a[i+1]<=a[i]){
            cout << sum-2*(a[i]-a[i+1]) << endl;
            continue;
        }
        if(a[i+1]<=a[i-1] && a[i-1]<=a[i]){
            cout << sum-2*(a[i]-a[i-1]) << endl;
            continue;
        }
        if(a[i+1]<=a[i] && a[i]<=a[i-1]){
            cout << sum << endl;
            continue;
        }
        if(a[i]<=a[i+1] && a[i+1]<=a[i-1]){
            cout << sum-2*(a[i+1]-a[i]) << endl;
            continue;
        }
        if(a[i]<=a[i-1] && a[i-1]<=a[i+1]){
            cout << sum-2*(a[i-1]-a[i]) << endl;
            continue;
        }
    }
} 