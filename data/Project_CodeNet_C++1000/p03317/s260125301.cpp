#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;


int main() {
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll m=0;
    
    // if(n==k){
    //     cout << 1 << endl;
    //     return 0;
    // }

    rep(i,n){
        if(a[i]==1){
            m=i+1;
        }
    }

    ll x1=m-1;
    ll x2=n-m;
    ll ans=0;
    k--;
    ll amari=k;
    while(x1>0){
        amari=x1;
        x1-=k;
        ans++;
    }
    x2-=(k-amari);
    while(x2>0){
        x2-=k;
        ans++;
    }

    cout << ans << endl;
}