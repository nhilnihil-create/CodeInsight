#include <bits/stdc++.h>
using namespace std;
string S;
int n, k, ans;
const int N = 305;
int F[N][N][N];
int main()
{
    cin >> S; n = S.size(); cin >> k;
    for (int l = 0; l < n; ++ l)
        for (int r = n - 1; r >= l; -- r)
            for (int c = 0; c <= k; ++ c)
                if (S[l] == S[r])
                {
                    F[l + 1][r - 1][c] = max(F[l + 1][r - 1][c], F[l][r][c] + 1);
                    ans = max(ans, F[l][r][c] * 2 + (l == r ? 1 : 2));
                }
                else
                {
                    if (c != k)
                        F[l + 1][r - 1][c + 1] = max(F[l + 1][r - 1][c + 1], F[l][r][c] + 1),
                        ans = max(ans, F[l][r][c] * 2 + 2);
                    F[l][r - 1][c] = max(F[l][r - 1][c], F[l][r][c]);
                    F[l + 1][r][c] = max(F[l + 1][r][c], F[l][r][c]);
                }
    cout << ans << endl;
}
