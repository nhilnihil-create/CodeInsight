#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void chmax(int &a, int b) {
    a = max(a, b);
}

char buf[310];
int dp[310][310][310];
int main() {
    scanf("%s", buf);
    int K; scanf("%d", &K);

    int N = strlen(buf);
    for(int i=0; i<N; i++) {
        dp[i][i+1][0] = 1;
    }

    for(int k=0; k<=K; k++) {
        for(int len=0; len<=N; len++) {
            for(int l=0; l<N-len+1; l++) {
                int r = l + len;
                if(k > 0) chmax(dp[l][r][k], dp[l][r][k-1]);
                if(l-1 >= 0 && r+1 <= N) {
                    int cost = (buf[l-1] != buf[r]);

                    // 変更する
                    if(k + cost <= K) chmax(dp[l-1][r+1][k+cost], dp[l][r][k] + 2);
                    
                    // 変更しない
                    chmax(dp[l-1][r+1][k], dp[l][r][k]);
                }
                if(l-1 >= 0) chmax(dp[l-1][r][k], dp[l][r][k]);
                if(r+1 <= N) chmax(dp[l][r+1][k], dp[l][r][k]);
            }
        }
    }

    /*
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<=N; j++) {
            printf("%s -> %d\n", buf, dp[i][j][K]);
            for(int x=0; x<N; x++) {
                if(i <= x && x < j) printf("=");
                else printf(" ");
            }
            printf("\n");
        }
    }
    */

    int ans = 0;
    for(int i=0; i<=K; i++) {
        chmax(ans, dp[0][N][i]);
    }
    printf("%d\n", ans);
    return 0;
}