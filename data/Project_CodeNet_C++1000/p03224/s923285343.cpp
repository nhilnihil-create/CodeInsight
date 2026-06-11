/*input
1
*/
#include <bits/stdc++.h>
#define db(x) cout<<#x<<"="<<(x)<<" "
#define el cout<<endl
using namespace std;
const int MXN = 1e5 + 10;

int N;
long long ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N; // n = N;
    for (int m = 1; m * (m + 1) <= N * 2; ++m)
    {
        if (m * (m + 1) == N * 2) {
            int cnt = 0;
            puts("Yes");
            printf("%d\n", m + 1);
            std::vector<std::vector<int>> ans(m + 1, vector<int>(m, 0));
            for (int i = 0; i <= m; ++i)
            {
                for (int j = 0; j < i; ++j)
                    ans[i][j] = (ans[j][i - 1]);
                for (int j = i; j < m; ++j)
                    ans[i][j] = (++cnt);
                printf("%d", m);
                for (int j = 0; j < m; ++j)
                    printf(" %d", ans[i][j]);
                printf("\n");
            }
            return 0;
        }
    }
    puts("No");
    return 0;
}
