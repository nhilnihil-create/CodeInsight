#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
vector<T> Vec(size_t l, T v) { return vector<T>(l, v); }

template <class T, class... Ts>
auto Vec(size_t l, Ts... ts) {
    return vector<decltype(Vec<T>(ts...))>(l, Vec<T>(ts...));
}

auto A = Vec<int>(0, 0);
auto pre = Vec<int>(0, 0, 0);
auto dp = Vec<int>(0, 0, 0, 0);

int rec(int L, int R, int K) {
    if (L > R) return 0;
    if (dp[L][R][K] >= 0) return dp[L][R][K];

    // 1. A[L]を使わない場合
    dp[L][R][K] = rec(L + 1, R, K);

    // 2. A[L]を使う場合
    //    Rの直前にあるA[L]を使う
    int gain = (pre[R][A[L]] == L ? 1 : 2);
    dp[L][R][K] = max(dp[L][R][K], rec(L + 1, pre[R][A[L]] - 1, K) + gain);

    // 3. A[L]を変更する場合
    //    A[L]をA[R]に変えるのが最善
    if (K > 0) {
        int gain = (L == R ? 1 : 2);
        dp[L][R][K] = max(dp[L][R][K], rec(L + 1, R - 1, K - 1) + gain);
    }

    return dp[L][R][K];
}

int main() {
    string S;
    int K;
    cin >> S >> K;
    int N = S.length();

    A = Vec<int>(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        A[i] = S[i - 1] - 'a';
    }

    pre = Vec<int>(N + 1, 26, -1);
    // pre[i][c] = j <= iかつA[j] = cなる最大のj

    for (int i = 1; i <= N; ++i) {
        for (int c = 0; c < 26; ++c) {
            if (A[i] == c) {
                pre[i][c] = i;
            } else {
                pre[i][c] = pre[i - 1][c];
            }
        }
    }
    dp = Vec<int>(N + 1, N + 1, K + 1, -1);

    cout << rec(1, N, K) << endl;
    return 0;
}
