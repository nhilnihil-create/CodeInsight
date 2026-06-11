#include <bits/stdc++.h>
using namespace std;

#define    ll    long long int

int main( )
{
    int n, T, t, i, c, ans = 1111;
    cin >> n >> T;
    for (i = 0; i < n; i++) {
        cin >> c >> t;
        if (t <= T) {
            ans = min(ans, c);
        }
    }
    if (ans == 1111) {
        cout << "TLE\n";
    }
    else {
        cout << ans << '\n';
    }
    return 0;
}

