#include <iostream>
using namespace std;

const int mod = 1000000007;

int N;
bool a[21][21];
int dp[1 << 21];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> a[i][j];

    dp[0] = 1;
    for(int S = 1; S < 1 << N; S++) {
        int i = __builtin_popcount(S);
        for(int j = 0; j < N; j++) {
            if(S >> j & 1 && a[i - 1][j] == 1) {
                dp[S] += dp[S ^ 1 << j];
                dp[S] %= mod;
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}