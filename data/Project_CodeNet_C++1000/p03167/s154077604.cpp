#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;
ll mod = 1e9+7;

int main() {
    ll h, w;    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
        cin >> s[i];

    vector<vector<ll> > dp(h, vector<ll>(w, 0));
    dp[0][0] = 1;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#')
                dp[i][j] = 0;
            if (i+1 < h) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= mod;
            }
            if (j+1 < w) {
                dp[i][j+1] += dp[i][j];
                dp[i][j+1] %= mod;
            }
        }
    }

    cout << dp[h-1][w-1] << endl;

    return 0;
}
