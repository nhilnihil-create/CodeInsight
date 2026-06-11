#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    string S;
    cin >> S;
    
    vector<int> N;
    rep(i, S.size()) N.push_back(S[i] - '0');
    vector<vector<int>> dp(N.size() + 1, vector<int>(2, -100100100));
    dp[0][0] = 0;
    rep(i, N.size()) rep(j, 2) {
        for (int x = 0; x <= (j ? 9 : N[i]); ++x) {
            dp[i + 1][j || x < N[i]] = max(dp[i + 1][j || x < N[i]], dp[i][j] + x);
        }
    }
    cout << max(dp[N.size()][0], dp[N.size()][1]) << endl;
    return 0;
}
