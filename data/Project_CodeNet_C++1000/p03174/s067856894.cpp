#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {

    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    bool compatible[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int a;
            cin >> a;

            compatible[i][j] = (a == 1);
        }
    }

    vector<int> dp((1 << n), 0);
    dp[0] = 1;
    for(int bitmask = 0; bitmask < (1 << n) - 1; bitmask++) {
        int man = __builtin_popcount(bitmask);
        for(int woman = 0; woman < n; woman++) {
            if(compatible[man][woman] && !(bitmask & (1 << woman))) {
                int m2 = bitmask ^ (1 << woman);
                dp[m2] = add(dp[bitmask], dp[m2]);
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
