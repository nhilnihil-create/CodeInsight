#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9+7;


int main() {
    ll k, a, b; cin >> k >> a >> b;
    k++;

    if(b - a <= 2 || k < a){
        cout << k << endl;
        return 0;
    }else{
        ll ans = a;
        k -= a;
        ans += (k / 2) * (b - a);
        ans += (k % 2);
        cout << ans << endl;
    }


    return 0;
}
