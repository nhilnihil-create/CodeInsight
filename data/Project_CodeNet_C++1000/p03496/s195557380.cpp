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
    vector<ll> a(n);
    ll val=-1;
    ll pos=-1;
    ll sg=-1;
    rep(i,n){
        cin >> a[i];
        if(val<abs(a[i])){
            val=abs(a[i]);
            pos=i;
            if(a[i]>=0){
                sg=1;
            }
            else{
                sg=0;
            }
        }
    }
    cout << 2*n-2 << endl;
    rep(i,n){
        if(i==pos) continue;
        a[i]+=a[pos];
        cout << pos+1 << " " << i+1 << endl;
    }
    if(sg){
        rep(i,n-1){
            cout << i+1 << " " << i+2 << endl;
        }
    }
    else{
        rep(i,n-1){
            cout << n-i << " " << n-i-1 << endl;
        }
    }
}