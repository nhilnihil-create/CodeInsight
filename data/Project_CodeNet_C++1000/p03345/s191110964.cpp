#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
using Graph = V<V<int>>;
const int MOD =  1000000007;
const ll INF = 1LL << 60;


int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k & 1) cout << b - a << endl;
    else cout << a - b << endl;

    return 0;
}
