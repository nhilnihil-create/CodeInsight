#include <bits/stdc++.h>

using namespace std;

template <class T> bool minimize(T &x, const T &y) {
    if (x > y) x = y; else return false; return true;
}

typedef long long ll;

const int N = 5e3 + 10;

int n;
ll A, B;
int a[N];
ll f[N][N];

int main() {
    if (fopen("B.inp", "r"))
        freopen("B.inp", "r", stdin),
        freopen("B.out", "w", stdout);
    cin >> n >> A >> B;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, 60, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++) {
            if (f[i][j] > (ll)(1e14)) continue;
            if (a[i + 1] > j) {
                /// not move
                minimize(f[i + 1][a[i + 1]], f[i][j]);
                /// move a[i + 1]
                minimize(f[i + 1][j], f[i][j] + A);
            } else
                minimize(f[i + 1][j], f[i][j] + B);
        }
    ll ret = f[0][1];
    for (int j = 0; j <= n; j++)
        minimize(ret, f[n][j]);
    cout << ret;
}
