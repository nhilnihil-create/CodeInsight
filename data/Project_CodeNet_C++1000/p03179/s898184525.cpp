
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 3e3, mod = 1e9 + 7;
int n, dp[nsz + 5][nsz + 5], pre[nsz + 5][nsz + 5], ans;
string s;

int inline upd(int &a, int b) {
    (a += b) && a >= mod && (a -= mod);
}

int inline modulo(int a) {
    return (a % mod + mod) % mod;
}

int inline qry(int i, int l, int r) {
    return modulo(pre[i][r] - pre[i][l - 1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> s;
    s = "  " + s;
    dp[1][1] = 1;
    cont (i, n) {
        pre[1][i] = pre[1][i - 1] + dp[1][i];
    }
    circ (i, 2, n) {
        cont (j, i) {
            dp[i][j] = (s[i] == '<') ? qry(i - 1, 1, j - 1) : qry(i - 1, j, n);
        }
        cont (j, n) {
            pre[i][j] = modulo(pre[i][j - 1] + dp[i][j]);
        }
    }
    cont (i, n) {
        upd(ans, dp[n][i]);
    }
    cout << ans << ln;
}