#include <bits/stdc++.h>

using namespace std;

int main (void) {
    long long N, M;
    cin >> N >> M;

    long long ans = 1;
    for ( long long i = 1; i * i <= M; i++ ) {
        if ( M % i != 0 )
            continue;

        long long x = M / i;
        if ( i * N <= M )
            ans = max(ans, i);
        if ( x * N <= M )
            ans = max(ans, x);
    }

    cout << ans << endl;
    return 0;
}
