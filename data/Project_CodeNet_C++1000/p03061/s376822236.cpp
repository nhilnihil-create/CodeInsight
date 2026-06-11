#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y);

signed main() {
    int n, a, left[100002], right[100002], ans;

    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> a;
        left[i+1] = a;
        right[i+1] = a;
    }

    left[0] = right[0] = left[n+1] = right[n+1] = 0;

    for ( int i = 0; i < n; i++ ) {
        left[i+1] = gcd(left[i], left[i+1]);
    }

    for ( int i = n; i > 0; i-- ) {
        right[i] = gcd(right[i], right[i+1]);
    }

    ans = 0;
    for ( int i = 1; i <= n; i++ ) {
        ans = max(ans, gcd(left[i-1], right[i+1]) );
    }

    cout << ans << endl;

    return (0);
}

int gcd(int x, int y) {
    if ( x < y ) {
        swap(x, y);
    }

    if ( y == 0 ) {
        return (x);
    } 

    int z = x % y;
    while ( z != 0 ) {
        x = y;
        y = z;
        z = x % y;
    }

    return (y);
}