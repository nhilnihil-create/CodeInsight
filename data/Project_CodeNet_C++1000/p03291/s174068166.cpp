#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>

using namespace std;
using ll = long long;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
/*----------------------------------------------------------------------------------*/

ll dp[100010][4];
const ll mod = 1e9+7;

int main() {
    string s; cin >> s;
    int len = s.size();

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    rep(i,len) {
        // カウントを進めない
        rep(j,4) {
            if (s[i] == '?') {
                (dp[i+1][j] += dp[i][j]*3) %= mod;
            } else {
                (dp[i+1][j] += dp[i][j]) %= mod;
            }
        }

        // 進める
        if (s[i] == '?' || s[i] == 'A') {
            (dp[i+1][1] += dp[i][0]) %= mod;
        }
        if (s[i] == '?' || s[i] == 'B') {
            (dp[i+1][2] += dp[i][1]) %= mod;
        }
        if (s[i] == '?' || s[i] == 'C') {
            (dp[i+1][3] += dp[i][2]) %= mod;
        }
    }

    cout << dp[len][3] << endl;
    return 0;
}
