#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (long long i = x; i < n; i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
// using ll = long long;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    char s[n + 2][m + 2];
    int res[n][m];

    rep(i, n + 2) rep(j, m + 2) s[i][j] = '.';

    rep(i, n) {
        string text;
        cin >> text;
        rep(j, m) { s[i + 1][j + 1] = text.at(j); }
    }


    arep(i, 1, n + 1) {
        arep(j, 1, m + 1) {
            ll cnt = 0;
            if (s[i][j] == '.') {
                ll left = j - 1;
                ll right = j + 1;
                ll top = i - 1;
                ll bot = i + 1;

                if (s[top][left] == '#') cnt++;
                if (s[top][j] == '#') cnt++;
                if (s[top][right] == '#') cnt++;
                if (s[i][left] == '#') cnt++;
                if (s[i][right] == '#') cnt++;
                if (s[bot][left] == '#') cnt++;
                if (s[bot][j] == '#') cnt++;
                if (s[bot][right] == '#') cnt++;
            }
            res[i - 1][j - 1] = cnt;
        }
    }

    rep(i, n) {
        rep(j, m) {
            if (res[i][j] == 0) {
                if (s[i + 1][j + 1] == '.') {
                    cout << 0;
                } else {
                    cout << s[i + 1][j + 1];
                }
            } else {
                cout << res[i][j];
            }
        }

        cout << endl;
    }
}