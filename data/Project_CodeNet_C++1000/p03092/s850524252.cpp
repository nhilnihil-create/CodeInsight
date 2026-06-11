#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int MAX_N = 5000 + 7;

int n;
int A[MAX_N];
int B[MAX_N];
int lmax[MAX_N][MAX_N], rmin[MAX_N][MAX_N];
ll l, r;
ll dp[MAX_N][MAX_N];


int main() {
    scanf("%d%lld%lld", &n, &r, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        B[A[i]] = i;
    }
    
    for (int k = 1; k <= n; k++) {
        int cnt = 0;
        for (int t = 1; t < k; t++) {
            if (A[t] > A[k])
                cnt++;
            lmax[t][A[k]] = cnt;
        }
    }
    
    for (int k = n; k >= 0; k--)
        for (int i = n; i >= 1; i--) {
            if (k == n || i == n)
                dp[k][i] = 0;
            else if (B[i] <= k) {
                dp[k][i] = dp[k][i + 1];
            }
            else {
                dp[k][i] = min(l + dp[k][i + 1], r * (lmax[B[i] - 1][i] - lmax[k][i]) + dp[B[i] - 1][i + 1]);
            }
        }

    /*for (int i = 1; i <= n; i++)
        printf("%d ", lmin[i]);
    printf("\n");
    for (int i = 1; i <= n; i++)
        printf("%d ", rmax[i]);
    printf("\n");*/

    /*for (int i = 0; i <= n; i++)
        dp[i][n - i] = 0;
    for (int sum = n - 1; sum >= 0; sum--)
        for (int i = 0; i <= sum; i++) {
            int j = sum - i;
            dp[i][j] = l + dp[i + 1][j];
            if (lmin[i + 1] >= n - j + 1)
                dp[i][j] = min(dp[i][j], dp[i + 1][j]);
            dp[i][j] = min(dp[i][j], r + dp[i][j + 1]);
            if (rmax[n - j] <= i)
                dp[i][j] = min(dp[i][j], dp[i][j + 1]);
            //printf("!!!!!%d %d: %lld\n", i, j, dp[i][j]);
        }*/
    printf("%lld\n", dp[0][1]);
}
