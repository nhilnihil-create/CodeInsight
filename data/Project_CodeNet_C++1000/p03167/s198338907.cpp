#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXH 1005
#define MAXW 1005
#define mod 1000000007
bool wall[MAXH][MAXW];
ll dp[MAXH][MAXW];
int main() {
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        string s; 
        cin >> s;
        for (int j = 1; j <= w; j++) {
            if (s[j - 1] == '#') {
                wall[i][j] = true;
            }
            else {
                wall[i][j] = false;
            }
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (!wall[i][j + 1]) {
                dp[i][j + 1] = (dp[i][j] + dp[i][j + 1]) % mod;
            }
            if (!wall[i + 1][j]) {
                dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % mod;
            }
        }
    }
    cout << dp[h][w] << endl;
    return 0;
}