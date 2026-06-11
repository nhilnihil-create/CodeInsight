//#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//ifstream cin("x.in"); ofstream cout("x.out");

const int nmax = 300 + 5;

string s;
int d[nmax + 1][nmax + 1][nmax + 1];

int main() {
    int q;
    cin >> s >> q;

    int n = (int)s.size();
    s = '#' + s;

    int ans = 0;

    for (int i = 1; i <= n; ++ i) {
        for (int j = n; j > i; -- j) {
            for (int k = 0; k <= q; ++ k) {
                d[ i ][ j ][ k ] = max(d[i - 1][ j ][ k ], d[ i ][j + 1][ k ]);

                if (k - 1 >= 0)
                    d[ i ][ j ][ k ] = max(d[ i ][ j ][ k ], d[ i ][ j ][k - 1]);

                if (s[ i ] == s[ j ])
                    d[ i ][ j ][ k ] = max(d[ i ][ j ][ k ], d[i - 1][j + 1][ k ] + 2);
                else if (k > 0)
                    d[ i ][ j ][ k ] = max(d[ i ][ j ][ k ], d[i - 1][j + 1][k - 1] + 2);
            }

            ans = max(ans, d[ i ][i + 1][ q ]);
            ans = max(ans, d[ i ][i + 2][ q ] + 1);
        }
    }

    if (n == 1)
        ans = 1;

    cout << ans << "\n";

    return 0;
}
