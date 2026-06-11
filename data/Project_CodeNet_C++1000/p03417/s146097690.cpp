#include <bits/stdc++.h>
using namespace std;

#define    ll     long long int

int main( )
{
    ll n, m, s;
    cin >> n >> m;
    if (n > m) swap(n, m);
    if (n == 1) {
        if (m == 1) {
            cout << "1\n";
            return 0;
        }
        cout << max(m - 2, 0LL) << '\n';
    }
    else {
        cout << ((n * m) - (2 * (n - 1) + 2 * (m - 1))) << '\n';
    }
    return 0;
}