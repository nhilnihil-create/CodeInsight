#include <bits/stdc++.h>

using namespace std;

const int MAX_HW = 1234;
int h, w;
long long dp[MAX_HW][MAX_HW];
char a[MAX_HW][MAX_HW];

int main() {
    
    cin >> h >> w;

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> a[i][j];

    dp[0][0] = 1;

    for (int i = 1; i < h; ++i) {
        if (a[i][0] != '#')
            dp[i][0] = dp[i - 1][0];

        else
            dp[i][0] = 0;
    }

    for (int i = 1; i < w; ++i) {
        if (a[0][i] != '#')
            dp[0][i] = dp[0][i - 1];

        else
            dp[0][i] = 0;
    }

    for (int i = 1; i < h; ++i)
        for (int j = 1; j < w; ++j)
            if (a[i][j] == '#')
                dp[i][j] = 0;

            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;

    cout << dp[h - 1][w - 1] << endl;
    return 0;
}
