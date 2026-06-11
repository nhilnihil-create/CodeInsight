#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> prime_factors(ll n) {
    map<ll, ll> res;
    if(n == 1){
        res[n] = 1;
        return res;
    }
    for(ll i = 2, _n = n; i*i <= _n; ++i){
        while(n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if(n != 1) res[n] = 1;
    return res;
}

int main() {
    ll N, P, x, y, z, ans = 1;
    cin >> N >> P;
    map<ll, ll> res = prime_factors(P);

    for(map<ll, ll>::iterator it = res.begin(), end = res.end(); it != end; ++it){
        // cout << it->first << "^" << it->second << endl;
        x = it->first;
        y = it->second;
        if(y >= N){
            z = y/N;
            // cout << x << "^" << y << endl;
            ans = ans * pow(x, z);
        }
    }

    cout << ans << endl;
    return 0;
}