#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll x, ll y){
    if(x < y) return gcd(y, x);
    if(x%y == 0) return y;
    return gcd(y, x%y);
}

int main(){
    ll n,x;
    cin >> n >> x;
    vector<ll>d(n);
    for(int i=0;i<n;i++){
        ll a;
        cin >> a;
        d[i] = abs(a - x);
    }
    ll ans = d[0];
    for(int i=1;i<n;i++) ans = gcd(ans, d[i]);

    cout << ans << endl;
}
