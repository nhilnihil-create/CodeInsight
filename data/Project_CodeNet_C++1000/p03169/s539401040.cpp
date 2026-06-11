#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define pb push_back
#define mp make_pair
using namespace std;

const long long mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> c(5, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        c[x]++;
    }
    double dp[305][305][305];
    for (int k = 0; k < 305; k++) {
        for (int j = 0; j + k < 305; j++) {
            for (int i = 0; i + j + k < 305; i++) {
                int sum = i + j + k;
                dp[i][j][k] = 0;
                if (sum == 0) continue;
                dp[i][j][k] += 1.0 * n / sum;
                if (i) dp[i][j][k] += 1.0 * i / sum * dp[i - 1][j][k];
                if (j) dp[i][j][k] += 1.0 * j / sum * dp[i + 1][j - 1][k];
                if (k) dp[i][j][k] += 1.0 * k / sum * dp[i][j + 1][k - 1];
            }   
        }
    }
    cout << fixed << setprecision(10) << dp[c[1]][c[2]][c[3]] << endl;
}

int main() {
    solve();
    return 0;
}