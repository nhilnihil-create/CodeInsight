// Strange Bank 配るDP
#include <iostream>
using namespace std;
int dp[100100];

int main () {
    int N; cin >> N;
    for (int i = 0; i < 100010; i++) dp[i] = N;
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int pow6 = 1; i + pow6 <= N; pow6 *= 6) {
            dp[i + pow6] = min(dp[i + pow6], dp[i] + 1);
        }
        for (int pow9 = 1; i + pow9 <= N; pow9 *= 9) {
            dp[i + pow9] = min(dp[i + pow9], dp[i] + 1);
        }
    }
    cout << dp[N] << endl;
}