#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll>PLL;
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll MOD = 1e4+7;
int main() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
//    rep(i, k) {
//        ll tmp_a = a;
//        ll tmp_b = b;
//        ll tmp_c = c;
//        a = tmp_b + tmp_c;
//        b = tmp_a + tmp_c;
//        c = tmp_a + tmp_b;
//    }
    if ( k & 1 ) swap(a, b);
    if ( abs(a - b) >= 1e18 ) cout << "Unfair" << endl;
    else                      cout << a - b << endl;
    return 0;
}
