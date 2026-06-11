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
    vector<ll> a(n),b(n);
    ll sum_a=0,sum_b=0;
    rep(i,n){
        cin >> a[i];
        sum_a+=a[i];
    }
    rep(i,n){
        cin >> b[i];
        sum_b+=b[i];
    }
    if(sum_b>sum_a){
        cout << -1 << endl;
        return 0;
    }
    ll tot=0;
    vector<ll> sup;
    ll ans=0;
    rep(i,n){
        if(a[i]<b[i]){
            tot+=b[i]-a[i];
            ans++;
        }
        if(a[i]>b[i]){
            sup.push_back(a[i]-b[i]);
        }
    }
    sort(sup.rbegin(),sup.rend());
    ll m=sup.size();
    ll sum=0;
    ll i=0;
    while(tot>0){
        tot-=sup[i];
        i++;
        ans++;
    }
    cout << ans << endl;
}
