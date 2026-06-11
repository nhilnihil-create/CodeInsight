#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <stack>
#include <iomanip>  
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i ++)
using ll = long long;
int N;
int A[301];
double dp[301][301][301];

double solve(int x, int y, int z) {
    if (dp[x][y][z] >= 0) return dp[x][y][z];
    double ans = 0;
    double m = x + y + z;
    if (x > 0) ans += solve(x - 1, y, z) * x / m;
    if (y > 0) ans += solve(x + 1, y - 1, z) * y / m;
    if (z > 0) ans += solve(x, y + 1, z - 1) * z / m;
    ans += (double)N / m;
    return dp[x][y][z] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    rep(i, N) cin >> A[i];
    int x = 0, y = 0, z = 0;
    rep(i, N) {
        if (A[i] == 1) x ++;
        if (A[i] == 2) y ++;
        if (A[i] == 3) z ++;
    }
    rep(i, 301) rep(j, 301) rep(k, 301) dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    cout << setprecision(15) << solve(x, y, z) << endl;
    return 0;
}