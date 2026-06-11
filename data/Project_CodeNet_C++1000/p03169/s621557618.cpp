#include <iostream>

using namespace std;
int sum[4];
double dp[301][301][2];

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0;i<N;i++) {
        int a;
        scanf("%d", &a);
        sum[a]++;
    }
    double fail;
    for (int k=0;k<=sum[3];k++)
        for (int j=0;j<=sum[3] + sum[2] - k;j++)
            for (int i=0;i<=N - j - k;i++) {
                fail = 1.0 / (1 - (double)(N - i - j - k)/N); 
                double divis = (i + j + k);

                dp[i][j][k % 2] = 0;

                if (i) {
                   
                    dp[i][j][k % 2] += i / divis * (dp[i - 1][j][k % 2]);
                }
                if (j)
                    dp[i][j][k % 2] += j / divis * (dp[i + 1][j - 1][k % 2]);
                if (k)
                    dp[i][j][k % 2] += k / divis * (dp[i][j + 1][(k + 1) % 2]);
                if (i + j + k) 
                    dp[i][j][k % 2] += fail;
            }

    printf("%.9lf\n", dp[sum[1]][sum[2]][sum[3] % 2] );
}