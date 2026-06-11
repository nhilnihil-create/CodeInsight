#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll g(ll a,ll b){
    while(b>0){
        ll y=a;
        a=b;
        b=y%a;
    }
    return a;
}

int main() {
    ll n,x; cin >> n >> x;
    vector<ll> p(n+1);
    rep(i,n) cin >> p[i];
    p[n]=x;
    sort(p.begin(),p.end());
    vector<ll> q(n);
    rep(i,n) q[i]=p[i+1]-p[i];
    ll gcd=0;
    rep(i,n) {
        gcd=g(gcd,q[i]);
    }
    cout << gcd << endl;
}