#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int MAX = 305;
// const int MAX = 4;
/* global variables */
int N;
double dp[MAX][MAX][MAX];
bool flag[MAX][MAX][MAX];
/* funciton */
void init() {
    for (int i = 0; i < MAX; i++) for (int j = 0; j < MAX; j++) for (int k = 0; k < MAX; k++) {
        dp[i][j][k] = 0;
        flag[i][j][k] = false;
    }
}
double f(int c1, int c2, int c3) {
    if (flag[c1][c2][c3]) return dp[c1][c2][c3];
    flag[c1][c2][c3] = true;
    double d = c1+c2+c3;
    double ret = (double)N / d;  // (1−(0個の皿が選ばれる確率))
    //  + dp[c1−1][c2][c3] * (1個の皿が選ばれる確率) / (1−(0個の皿が選ばれる確率))
    if (c1 > 0) ret += f(c1-1, c2, c3) * c1 / d;
    //  + dp[c1+1][c2−1][c3] * (2個の皿が選ばれる確率) / (1−(0個の皿が選ばれる確率))
    if (c2 > 0) ret += f(c1+1, c2-1, c3) * c2 / d;
    //  + dp[c1][c2+1][c3−1] * (3個の皿が選ばれる確率) / (1−(0個の皿が選ばれる確率))
    if (c3 > 0) ret += f(c1, c2+1, c3-1) * c3 / d;
    return dp[c1][c2][c3] = ret;
}
/* main */
int main() {
    cin >> N;
    vector<int> cnt(4, 0);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        cnt[a]++;
    }
    // dp[c1][c2][c3]
    // =(1個の皿:c1枚,2個の皿:c2枚,3個の皿:c3枚あるとき,全て食べるまでの操作回数の期待値)
    // 遷移)
    // dp[c1][c2][c3]
    // = 1
    //  + dp[c1−1][c2][c3] * (1個の皿が選ばれる確率)
    //  + dp[c1+1][c2−1][c3] * (2個の皿が選ばれる確率)
    //  + dp[c1][c2+1][c3−1] * (3個の皿が選ばれる確率)
    //  + dp[c1][c2][c3] * (0個の皿が選ばれる確率)
    // ---- dp[c1][c2][c3]を移項 ----
    // dp[c1][c2][c3]
    // = 1 / (1−(0個の皿が選ばれる確率))
    //  + dp[c1−1][c2][c3] * (1個の皿が選ばれる確率) / (1−(0個の皿が選ばれる確率))
    //  + dp[c1+1][c2−1][c3] * (2個の皿が選ばれる確率) / (1−(0個の皿が選ばれる確率))
    //  + dp[c1][c2+1][c3−1] * (3個の皿が選ばれる確率) / (1−(0個の皿が選ばれる確率))
    flag[0][0][0] = true;
    double ans = f(cnt[1], cnt[2], cnt[3]);
    cout << fixed << setprecision(10) <<  ans << '\n';
}