#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;


int main(void) {
    int n, i, t, c, dp[200003] = {}, sd[200003] = {};
    const int mod = 1e9 + 7;
    vector<int> cv;

    cv.push_back(0);
    t = 1;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> c;
        if (c != cv[t - 1]) {
            cv.push_back(c);
            t++;
        }
    }

    dp[0] = 1;
    sd[0] = 1;
    for (i = 0; i < t; i++) {
        dp[i] = sd[cv[i]];
        sd[cv[i + 1]] = (sd[cv[i + 1]] + dp[i]) % mod;
    }

    cout << dp[t - 1] << endl;

    return 0;
}