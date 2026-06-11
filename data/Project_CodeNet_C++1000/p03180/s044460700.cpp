#include <iostream>
using namespace std;

int N;
int a[20][20];

long long dp[1 << 16];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> a[i][j];

    for(int S = 1; S < 1 << N; S++) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < i; j++)
                if(S >> i & S >> j & 1) dp[S] += a[i][j];

        for(int T = S; T > 0; T = T - 1 & S) {
            if(T == S) continue; // S 自身は除く
            dp[S] = max(dp[S], dp[T] + dp[S ^ T]);
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}