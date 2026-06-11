#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int t[n], v[n];
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    int dp[2][101] = {}, cur = 0, prev = 1;
    const int INF = 1<<30;
    fill(dp[prev]+1, dp[prev]+101, -INF);
    for (int i = 0; i < n; i++) {
        int vmax= v[i];
        while (t[i]--) {
            for (int v = 0; v <= 100; v++) {
                int temp = -INF;
                if (v < vmax) temp = dp[prev][v] + 4 * v + 1;
                if (v <= vmax && v > 0)
                    temp = max(temp, dp[prev][v-1] + 4 * v - 2);
                if (v < vmax && v < 100)
                    temp = max(temp, dp[prev][v+1] + 4 * v + 2);
                if (v <= vmax)
                    temp = max(temp, dp[prev][v] + 4 * v);
                dp[cur][v] = temp;
            }
            swap(cur, prev);
        }
    }
    cout << setprecision(12) << dp[prev][0] * 0.25 << endl;
}
