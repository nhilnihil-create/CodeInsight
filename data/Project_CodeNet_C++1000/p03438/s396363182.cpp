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
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e18;
const ll mod=1e9+7;


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
    ll cnt=sum_b-sum_a;
    ll tot=0;
    ll odd=0;
    rep(i,n){
        ll diff=b[i]-a[i];
        if(diff<0) tot+=a[i]-b[i];
        else{
            if(diff%2==1) odd++;
        }
    }
    if(tot+odd>cnt) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
