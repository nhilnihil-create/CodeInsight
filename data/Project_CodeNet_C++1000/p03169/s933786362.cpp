#include <bits/stdc++.h>
using namespace std;
double dp[305][305][305];
bool done[305][305][305];
int n;
double dfs(int a, int b, int c) {
    if (done[a][b][c]) return dp[a][b][c];
    if (a == 0 && b == 0 && c == 0) return 0;
    done[a][b][c] = true;
    double ret = 0;
    double n_p = (double)n;
    double a_p = (double)a / n_p, b_p = (double)b / n_p, c_p = (double)c / n_p;
    n_p = 1 / (1 - (double)(n - a - b - c) / n_p);
    ret += n_p;
    if (a > 0) ret += dfs(a-1, b, c) * n_p * a_p;
    if (b > 0) ret += dfs(a + 1, b - 1, c) * n_p * b_p;
    if (c > 0) ret += dfs(a, b + 1, c - 1) * n_p * c_p;
    // printf("%f, %f, %f\n", a_p, b_p, c_p);
    return dp[a][b][c] = ret;
}
int main() {
    cin >> n;
    int cnt[4] = {0, 0, 0, 0};
    for (int i = 0; i < 305; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++)
        done[i][j][k] = false;
    for (int i = 0; i < n; i++) {
        int a_temp;
        cin >> a_temp;
        cnt[a_temp]++;
    }
    // cout << cnt[1] << endl;
    // cout << cnt[2] << endl;
    // cout << cnt[3] << endl;
    // cout << dfs(1, 1, 1) << endl;
    cout << fixed << setprecision(20) << dfs(cnt[1], cnt[2], cnt[3]) << endl;
    return 0;
}
