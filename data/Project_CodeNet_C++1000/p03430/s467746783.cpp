#include <bits/stdc++.h>
using namespace std;

string s;
int mat[311][311][311];

int main()
{
    cin >> s;
    int kmax;
    cin >> kmax;
    int n = s.size();
    s = "$" + s;
    int ans(0);
    for (int i(1); i <= n; i++) {
        for (int j(1); i + j <= n; j++) {
            for (int k(0); k <= kmax; k++) {
                if (s[i] == s[n - j + 1])
                    mat[i][j][k] = mat[i - 1][j - 1][k] + 1;
                if (k > 0)
                    mat[i][j][k] = max(mat[i][j][k], mat[i - 1][j - 1][k - 1] + 1);
                mat[i][j][k] = max(mat[i][j][k], mat[i - 1][j][k]);
                mat[i][j][k] = max(mat[i][j][k], mat[i][j - 1][k]);
            }
        }
    }

    for (int i(1); i <= n; i++)
        for (int j(0); j <= kmax; j++)
            ans = max(ans, 2 * mat[i][n - i][j]);
    for (int i(1); i <= n; i++)
        for (int j(0); j <= kmax; j++)
            ans = max(ans, 2 * mat[i - 1][n - i][j] + 1);

    cout << ans << '\n';

    return 0;
}
