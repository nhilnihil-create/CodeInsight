#include <iostream>
#include <string>
using namespace std;

const int mod = 1000000007;

int N;
string s;

long long dp[3009][3009];

int main() {
    cin >> N >> s;

    for(int j = 0; j < N; j++)
        dp[0][j] = 1;

    for(int i = 0; i < N - 1; i++) {
        // 累積和
        long long sum[3009];
        sum[0] = 0;
        for(int j = 0; j < N - i; j++)
            sum[j + 1] = (sum[j] + dp[i][j]) % mod;

        if(s[i] == '<') {
            for(int j = 0; j < N - i; j++)
                dp[i + 1][j] = (sum[N - i] - sum[j + 1] + mod) % mod;
        }
        if(s[i] == '>') {
            for(int j = 0; j < N - i; j++)
                dp[i + 1][j] = sum[j + 1];
        }
    }

    cout << dp[N - 1][0] << endl;

    return 0;
}
