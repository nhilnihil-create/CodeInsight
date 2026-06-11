#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;  cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    ll tmp = 1;
    for (int i = 0; i < n; i++)
        tmp *= 2;
    ll mod = 1e9+7;

    vector<ll> dp(tmp, 0);
    dp[0] = 1;

    for (int s = 0; s < (1<<n); s++) {
        int i = 0;
        for (int j = 0; j < n; j++) {
            if ((s>>j) & 1)
                i++;
        }

        for (int j = 0; j < n; j++) {
            if (s>>j & 1 && a[i-1][j])
                dp[s] += dp[s^(1<<j)];
            dp[s] %= mod; 
        }
    }

    cout << dp[tmp-1] << endl;
    return 0;
}