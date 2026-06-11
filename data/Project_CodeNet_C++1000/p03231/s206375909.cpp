#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;

template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main() {
    ll n, m; cin >> n >> m;
    string s, t; cin >> s >> t;

    ll l = lcm(n, m);
    bool flag = true;
    for(ll i = 0; i < gcd(n, m); i++){
        if(s[l / m * i] == t[l / n * i]) continue;
        else{
            flag = false;
            break;
        }
    }
    if(flag) cout << l << endl;
    else cout << -1 << endl;

    return 0;
}
