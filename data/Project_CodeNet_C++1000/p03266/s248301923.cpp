#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, K;
    cin >> N >> K;

    int n = 0;
    int half_n = 0;
    for ( int i = 1; i <= N; i++ ) {
        if ( K % 2 == 0 ) {
            if ( i % K == 0 )
                n++;
            else if ( i % (K / 2) == 0 )
                half_n++;
        } else {
            if ( i % K == 0 )
                n++;
        }
    }

    cout << (long long)n * n * n + (long long)half_n * half_n * half_n << endl;
    return 0;
}
