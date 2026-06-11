#include <cstdio>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

long long dp[2][3000];
char s[3001];

int main()
{
    int N;
    scanf("%d", &N);
    scanf("%s", s);

    for (int i = 0; i < N; i++) dp[0][i] = 1;
    int t = 0;
    for (int i = 1; i < N; i++) {
        long long tot = 0;
        if (s[i - 1] == '>') {
            for (int j = 0; j <= N - 1; j++) {
                tot = (tot + dp[t][j]) % MOD;
                if (j <= N - i - 1) dp[1 - t][j] = tot;
                else dp[1 - t][j] = 0;
            }
        }
        else {
            for (int j = N - 1; j >= 0; j--) {
                if (j <= N - i - 1) dp[1 - t][j] = tot;
                else dp[1 - t][j] = 0;
                tot = (tot + dp[t][j]) % MOD;
            }
        }
        t = 1 - t;
    }
    printf("%lld\n", dp[t][0]);
    return 0;
}