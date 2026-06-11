#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef pair<int, int> par;
typedef pair<par, int> prr;
#define x first
#define y second
int dp[305][305][305];
int main(){
    string S, T;
    cin >> S;
    T = S;
    reverse(T.begin(), T.end());
    int n = S.size();
    S = "a" + S;
    T = "a" + T;
    int maxx;
    scanf("%d", &maxx);
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
        for (int k = 0; k <= maxx; k++) {
            dp[i][j][k] = max(dp[i][j - 1][k], dp[i - 1][j][k]);
            if (S[i] == T[j]) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + 1);
            else {
                if (k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1] + 1);
            }
        }
    }
    int ans = 0;
    for (int mid = 1; mid <= n; mid++) {
        int a = mid;
        int b = n - mid;
        for (int i = 0; i <= maxx; i++) {
            int tmp = dp[a][b][i] * 2;
            ans = max(ans, tmp);
        }
    }
    for (int mid = 1; mid <= n; mid++) {
        int a = mid - 1;
        int b = n - mid;
        for (int i = 0; i <= maxx; i++) {
            int tmp = dp[a][b][i] * 2 + 1;
            ans = max(ans, tmp);
        }
    }

    printf("%d\n", ans);
}
