#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    ll c;
    while(b>0){
        c=a;
        a=b;
        b=c%a;
    }
    return a;
}

int main(){
    ll n; cin >> n;
    ll ans=0;
    rep(i,n){
        ll x;
        cin >> x;
        ans=gcd(x,ans);
    }
    cout << ans << endl;
}