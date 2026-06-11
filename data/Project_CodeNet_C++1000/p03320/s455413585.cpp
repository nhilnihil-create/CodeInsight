#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 300005;
const ll K = ll(2e16);
int n, c;
ll x[N];
vector<ll> a;

ll f(ll x){
    ll r = 0;
    while(x){
        r += x % 10;
        x /= 10;
    }
    return r;
}

int main(){
    for(int i = 1; i < 10000; i++) x[c++] = i;
    for(ll t = 9; t < 9999999999999LL; t = 10 * t + 9){
        for(int j = 1000; j <= 9999; j++){
            ll v = j * (t + 1) + t;
            if(v < K) x[c++] = v;
        }
    }
    ll ma = f(x[c - 1]), mb = x[c - 1];
    for(int i = c - 2; i >= 0; i--){
        ll ca = f(x[i]), cb = x[i];
        if(cb * ma <= mb * ca){
            a.push_back(x[i]);
            ma = ca; mb = cb;
        }
    }
    reverse(a.begin(), a.end());
    scanf("%d", &n);
    for(int i = 0; i < n; i++) printf("%lld\n", a[i]);
}