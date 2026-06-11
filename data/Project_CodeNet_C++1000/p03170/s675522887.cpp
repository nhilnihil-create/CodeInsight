#include <iostream>
#include <vector>
using namespace std;

// DP テーブル (配列全体が false に自然に初期化される)
bool dp[110000]; // 局面数は最大 100001 だが少し余裕もたせる

int main() {
    // 入力受け取り
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // DP
    for (int i = 1; i <= K; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i - a[j] >= 0) dp[i] |= !dp[i - a[j]];
        }
    }

    // 答え
    if (dp[K]) cout << "First" << endl;
    else cout << "Second" << endl;
}