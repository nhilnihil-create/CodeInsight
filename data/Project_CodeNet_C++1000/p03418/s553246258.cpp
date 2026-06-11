#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int n, k;
    cin >> n >> k;

    long long ans = 0;
    for ( int b = k+1; b <= n; b++ ) {
        ans += max(0, b-k) * (n / b);
        ans += max(0, n%b-k+1);
        if ( k == 0 ) ans--;    /* 0 の分を引く */
    }

    cout << ans << endl;
    return 0;
}
