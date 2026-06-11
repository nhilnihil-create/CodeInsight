#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, ans = 0;
    cin >> n;
    char s[n][n] = {};
    rep(i, n) rep(j, n) cin >> s[i][j];

    rep(q, n)
    {
        rep(i, n) rep(j, n)
        {
            if (s[(q + i) % n][(j + n - q) % n] != s[j % n][i % n])
                goto enl;
        }
        ans++;
    enl:
        continue;
    }

    cout << ans * n << endl;

    return 0;
}
