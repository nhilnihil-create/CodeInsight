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
    vector<ll> divisors;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            if(i*i==n) divisors.push_back(i);
            else{
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
    }
    ll ans=0;
    for(auto r:divisors){
        if(n%r==0){
            ll m=n/r-1;
            if(r<=m-1) ans+=m;
        }
    }
    cout << ans << endl;
}
