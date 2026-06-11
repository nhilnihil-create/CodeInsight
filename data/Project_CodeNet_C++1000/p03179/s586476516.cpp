#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, i, j, dp[3003][3003] = {}, ps;
    string s;

    scanf("%d", &n);
    cin >> s;

    for (j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    for (i = 0; i < n - 1; i++) {
        if (s[i] == '<') {
            ps = 0;
            for (j = 0; j < n - i - 1; j++) {
                ps = (ps + dp[i][j]) % mod;
                dp[i + 1][j] = ps;
            }
        }
        else {
            ps = 0;
            for (j = n - 1; j >= 0; j--) {
                dp[i + 1][j] = ps;
                ps = (ps + dp[i][j]) % mod;
            }
        }
    }

    printf("%d\n", dp[n - 1][0]);

    return 0;
}