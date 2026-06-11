#include <bits/stdc++.h>

#define PB emplace_back

using namespace std;

const int N = 22;

long long int dp[1<<N], mod = 1e9+7;

bool b[N][N];

int main () {
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++ ) {
        for(int j = 0 ; j < n ; j++ ) {
            cin >> b[i][j];
        }
    }
    dp[0] = 1;
    for(int i = 1 ; i < (1 << n) ; i++ ) {
        int cnt = __builtin_popcount(i);
        for(int j = 0 ; j < n ; j++ ) {
            if(i & (1 << j)) {
                if(b[j][cnt-1]) {
                    dp[i] += dp[i ^ (1 << j)];
                    dp[i] %= mod;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1];
}
