#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int c[3][3];
int main() {
    rep(i, 3) rep(j, 3) cin >> c[i][j];

    rep(a1, 101) rep(a2, 101) rep(a3, 101) {
        int b1 = c[0][0] - a1;
        int b2 = c[0][1] - a1;
        int b3 = c[0][2] - a1;
        if (c[1][0] == a2 + b1 && c[2][0] == a3 + b1 && c[1][1] == a2 + b2 && c[2][1] == a3 + b2 && c[1][2] == a2 + b3 &&
            c[2][2] == a3 + b3) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}