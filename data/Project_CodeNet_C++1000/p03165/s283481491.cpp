#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(r) (r).begin(), (r).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;

const int MAX_L = 3010;
string S, T, R = "";
int x, y;
int dp[MAX_L][MAX_L] = {0};

int main() {
    cin >> S >> T;
    x = S.size(), y = T.size();

    rep(i, x) {
        rep(j, y) {
            if (S[i] == T[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
        }
    }
    // cout << dp[x][y] << endl;
    while (x > 0 && y > 0) {
        if (dp[x][y] == dp[x-1][y]) x--;
        else if (dp[x][y] == dp[x][y-1]) y--;
        else {
            R.push_back(S[x-1]);
            x--; y--;
        }
    }
    reverse(ALL(R));
    cout << R << endl;
}
