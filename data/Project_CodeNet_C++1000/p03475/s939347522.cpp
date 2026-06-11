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

ll calc(ll d, ll s, ll c, ll f) {
    if (d < s) {
        return d + (s - d) + c;
    }
    if (d % f == 0) {
        return d + c;
    }
    ll tmp = d % f;
    return d + c - tmp + f;
}
int main() {
    ll N;
    cin >> N;
    vector<ll> C(N);
    vector<ll> S(N);
    vector<ll> F(N);
    rep(i, N - 1) { cin >> C[i] >> S[i] >> F[i]; }
    rep(i, N - 1) {
        ll d = S[i] + C[i];
        for (ll j = i + 1; j < N - 1; j++) {
            d = calc(d, S[j], C[j], F[j]);
        }
        cout << d << endl;
    }
    cout << 0 << endl;

    return 0;
}
