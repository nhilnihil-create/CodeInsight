#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

template <class T>
bool chmax(T &a, T b) {if (a < b) {a = b; return true;} return false;}

int main() {
    int N;
    lint K;
    cin >> N >> K;
    vector<int> K2(50, 0);
    rep(i, 50) K2[49 - i] = (K >> i) & 1;
    vector<lint> A(N);
    rep(i, N) cin >> A[i];
    vector<vector<lint>> dp(51, vector<lint>(2, -1));
    dp[0][0] = 0;
    rep(i, 50) rep(j, 2) {
        if (dp[i][j] == -1) continue;
        for (int x = 0; x <= (j ? 1 : K2[i]); ++x) {
            lint res = 0;
            rep(k, N) {
                if ((A[k] >> (49 - i) & 1) ^ x) ++res;
            }
            res = res << (49 - i);
            chmax(dp[i + 1][j || x < K2[i]], dp[i][j] + res);
        }
    }
    cout << max(dp[50][0], dp[50][1]) << "\n";
    return 0;
}
