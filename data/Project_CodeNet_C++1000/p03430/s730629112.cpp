#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template<class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    string S;
    int K;
    cin >> S >> K;
    int N = (int)S.size();
    auto dp = make_vec<int>(N+2, N+2, K+2);
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            for (int k = 0; k <= K; ++k) {
                chmax(dp[i+1][j][k], dp[i][j][k]);
                chmax(dp[i][j+1][k], dp[i][j][k]);
                chmax(dp[i+1][j+1][k+1], dp[i][j][k] + 1);
                if (i < N && N-1-j >= 0 && S[i] == S[N-1-j])
                    chmax(dp[i+1][j+1][k], dp[i][j][k] + 1);
            }
        }
    }
    int res = 0;
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= N; ++i) chmax(res, dp[i][N-i][k] * 2);
        for (int i = 0; i < N; ++i) chmax(res, dp[i][N-1-i][k] * 2 + 1);
    }
    cout << res << endl;
}