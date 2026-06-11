#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    a--;
    if (a<0) a++;
    ll va = 0, vb = 0;
    vector<ll> places(44,0);
    for (ll i=1; i<=44; i++) {
        ll x = 1;
        for (ll j=0; j<i; j++) x*=2;
        ll y = b;
        places[i-1] = (b/x)*(x/2);
        y%=x;
        y-=(x/2)-1;
        if (y>0) places[i-1] += y;
        y = a;
        places[i-1] -= (a/x)*(x/2);
        y%=x;
        y-=(x/2)-1;
        if (y>0) places[i-1] -= y;
    }
    for (ll i=0; i<44; i++) places[i]%=2;
    ll res = 0;
    for (ll i=0; i<44; i++) if (places[i]>0) {
        ll x = 1;
        for (ll j=0; j<i; j++) x*=2;
        res+=x;
    }
    cout << res;
    return 0;
}