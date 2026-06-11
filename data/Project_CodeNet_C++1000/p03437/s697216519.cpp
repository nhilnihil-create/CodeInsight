#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll>PLL;
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll MOD = 1e4+7;
ll gcd ( ll a, ll b ) {
    if ( a % b == 0 ) return b;
    return gcd(b, a % b);
}
int main() {
    ll x, y;
    cin >> x >> y;
    ll gcd_num = gcd(x, y);
    if ( y == gcd_num ) {
        cout << -1 << endl;
        return 0;
    }
    ll mult_num = 2;
    while ( 1 ) {
        if ( x * mult_num > 1e18 ) {
            cout << -1 << endl;
            return 0;
        }
        if ( ( x * mult_num ) % y != 0 ) break;
        ++mult_num;
    }
    cout << x * mult_num << endl;
    return 0;
}

