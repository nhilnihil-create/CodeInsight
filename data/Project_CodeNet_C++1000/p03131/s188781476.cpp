#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair < ll, ll > PLL;
#define rep(i,n) for (int i = 0; i < (n); ++i)
int main() {
    ll k, a, b;
    cin >> k >> a >> b;
    if ( b - a <= 2 ) {
        cout << 1 + k << endl;
    }
    else if ( ( k - ( a - 1 ) ) % 2 == 0 ) {
        cout << a + ( k - ( a - 1 ) ) / 2 * ( b - a ) << endl;
    }
    else {
        cout << a + ( k - ( a - 1 ) ) / 2 * ( b - a ) + 1 << endl;
    }
    return 0;
}
