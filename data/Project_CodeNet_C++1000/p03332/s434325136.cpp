#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 998244353;

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return ((ll)a*b)%MOD;
}

int pw(int a, int b){
    if(b == 0) return 1;
    int res = pw(a, b/2);
    res = mul(res, res);
    if(b%2) res = mul(res, a);
    return res;
}

int inv(int a){
    return pw(a, MOD-2);
}

int fact[1000005];

int bcof(int n, int k){
    if(n < 0 || k < 0 || n < k) return 0;
    int res = fact[n];
    res = mul(res, inv(fact[k]));
    res = mul(res, inv(fact[n-k]));
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    fact[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = mul(fact[i-1], i);
    }
    ll a, b, k;
    cin >> a >> b >> k;
    int res = 0;
    for(int i=0; i*a<=k && i<=n; i++){
        ll c = k - (i*a);
        if(c%b) continue;
        c /= b;
        res = add(res, mul(bcof(n, i), bcof(n, c)));
    }
    cout << res;
    return 0;
}
