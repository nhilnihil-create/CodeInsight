#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

#define MAXN 301
#define mod 1000000007

char S[MAXN];
int N;
int dp[MAXN][MAXN][MAXN];

void print(int k) {
    string tmp(S);
    for (int len = 1; len <= N; len++) {
        for (int i = 0; i + len - 1 < N; i++) {
            int j = i + len - 1;
            printf("dp[%d][%d][%d] = %d, %s\n", k, i, j, dp[k][i][j], tmp.substr(i, len).c_str());
        }
    }
    printf("\n");
}

void f(int k) {
    for (int i = 0; i < N; i++) {
        dp[k][i][i] = 1;
    }

    for (int len = 2; len <= N; len++) {
        for (int i = 0; i + len - 1 < N; i++) {
            int j = i + len - 1;
            if (S[i] == S[j]) {
                if (len == 2) {
                    dp[k][i][j] = 2;
                } else {
                    dp[k][i][j] = dp[k][i + 1][j - 1] + 2;
                }
            } else {
                if (k == 0) {
                    if (len == 2) {
                        dp[k][i][j] = 1;
                    } else {
                        dp[k][i][j] = max(dp[k][i + 1][j - 1], max(dp[k][i][j - 1], dp[k][i + 1][j]));
                    }
                } else {
                    if (len == 2) {
                        dp[k][i][j] = 2;
                    } else {

                        dp[k][i][j] = max(dp[k - 1][i + 1][j - 1] + 2, max(dp[k][i][j - 1], dp[k][i + 1][j]));
                    }
                }
            }
        }
    }
}

int main() {
#ifdef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    //    freopen("output.txt", "wt", stdout);
#endif

    scanf("%s", S);
    N = strlen(S);

    int K;
    scanf("%d", &K);

    for (int i = 0; i <= K; i++) {
        f(i);
    }

    //    print(0);
    //    print(1);
    int ans = dp[K][0][N - 1];
    //    for (int i = 0; i <= K; i++)
    //        ans = max(ans, dp[i][0][N - 1]);

    printf("%d\n", ans);
    return 0;
}