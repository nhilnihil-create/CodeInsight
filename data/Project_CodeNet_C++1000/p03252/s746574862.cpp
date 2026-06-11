#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const int MAX = 1000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long INF = 1LL << 60;

int main() {
    string S, T;
    cin >> S >> T;
    vector<char> start(26, -1);
    vector<char> goal(26, -1);

    rep(i, S.length()) {
        ll start_index = S[i] - 'a';
        ll goal_index = T[i] - 'a';
        if (start[start_index] != -1 || goal[goal_index] != -1) {
            if (start[start_index] != T[i] || goal[goal_index] != S[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
        start[start_index] = T[i];
        goal[goal_index] = S[i];
    }
    cout << "Yes" << endl;
    return 0;
}
