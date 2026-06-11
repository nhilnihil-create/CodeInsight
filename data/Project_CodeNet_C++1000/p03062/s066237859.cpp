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
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    rep(i, N) { cin >> A[i]; }
    copy(A.begin(), A.end(), B.begin());
    copy(A.begin(), A.end(), C.begin());
    rep(i, N) { C[i] = abs(C[i]); }

    vector<ll>::iterator min_iter = min_element(C.begin(), C.end());
    ll min_index = distance(C.begin(), min_iter);
    ll ans = 0;

    for (ll i = 0; i != min_index; i++) {
        ll first = A[i];
        ll second = A[i + 1];
        if (first > 0 && second > 0) {
            continue;
        } else if (first < 0 && second < 0) {
            A[i] *= -1;
            A[i + 1] *= -1;
        } else if (first < 0 && second >= 0) {
            A[i] *= -1;
            A[i + 1] *= -1;
        }
    }
    for (ll i = A.size() - 1; i != min_index; i--) {
        ll first = A[i];
        ll second = A[i - 1];
        if (first > 0 && second > 0) {
            continue;
        } else if (first < 0 && second < 0) {
            A[i] *= -1;
            A[i - 1] *= -1;
        } else if (first < 0 && second >= 0) {
            A[i] *= -1;
            A[i - 1] *= -1;
        }
    }
    ans = accumulate(A.begin(), A.end(), 0LL);

    for (ll i = B.size() - 1; i != min_index; i--) {
        ll first = B[i];
        ll second = B[i - 1];
        if (first > 0 && second > 0) {
            continue;
        } else if (first < 0 && second < 0) {
            B[i] *= -1;
            B[i - 1] *= -1;
        } else if (first < 0 && second >= 0) {
            B[i] *= -1;
            B[i - 1] *= -1;
        }
    }
    for (ll i = 0; i != min_index; i++) {
        ll first = B[i];
        ll second = B[i + 1];
        if (first > 0 && second > 0) {
            continue;
        } else if (first < 0 && second < 0) {
            B[i] *= -1;
            B[i + 1] *= -1;
        } else if (first < 0 && second >= 0) {
            B[i] *= -1;
            B[i + 1] *= -1;
        }
    }
    ans = max(ans, accumulate(B.begin(), B.end(), 0LL));

    cout << ans << endl;
    return 0;
}
