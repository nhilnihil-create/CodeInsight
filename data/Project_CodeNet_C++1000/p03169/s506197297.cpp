#include <bits/stdc++.h> 
#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
 
#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif
 
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
 
using namespace std;
 
const int MX = 307;
 
ld f[MX + 5][MX + 5][MX + 5];
 
int main() {
    int n;
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            c1++;
        } else if (x == 2) {
            c2++;
        } else {
            c3++;
        }
    }
 
    for (int k = 0; k < MX; k++) {
        for (int j = 0; j + k < MX; j++) {
            for (int i = 0; i + j + k < MX; i++) {
                if (i == 0 && j == 0 && k == 0) {
                    continue;
                }
                if (i + j + k > MX) {
                    continue;
                }
                ld wait = 1.0 * n / (i + j + k);
                ld pi = 1.0 * i / (i + j + k);
                ld pj = 1.0 * j / (i + j + k);
                ld pk = 1.0 * k / (i + j + k);
 
                if (i) {
                    f[i][j][k] += pi * f[i - 1][j][k];
                }
                if (j) {
                    f[i][j][k] += pj * f[i + 1][j - 1][k];
                }
                if (k) {
                    f[i][j][k] += pk * f[i][j + 1][k - 1];
                }
                f[i][j][k] += wait;
            }
        }
    }
 
    cout.precision(10);
    cout << fixed << f[c1][c2][c3] << "\n";
    return 0;
}