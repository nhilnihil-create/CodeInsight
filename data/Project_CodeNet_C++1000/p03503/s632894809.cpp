#include <bits/stdc++.h>
using namespace std;

#define      ll     long long int

const int inf = 1e9 + 9;
int F[111][12];
int P[111][12];

int main()
{
    int n, i, j, k;
    cin >> n;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 10; j++) {
            cin >> F[i][j];
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= 10; j++) {
            cin >> P[i][j];
        }
    }
    int res = -inf;
    for (k = 1; k < 1024; k++) {
        int cur = 0;
        for (i = 1; i <= n; i++) {
            int c = 0;
            for (j = 1; j <= 10; j++) {
                if ((k & (1<<(j - 1))) != 0 && F[i][j] == 1) {
                    c++;
                }
            }
            cur += P[i][c];
        }
        res = max(res, cur);
    }
    cout << res << '\n';
    return 0;
}
