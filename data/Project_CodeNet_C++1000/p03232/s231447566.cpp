#include<iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

ll A[MAX_N], prob[MAX_N];

ll calc_pow(ll x, ll y) {
    ll z = 1;
    while (y > 0) {
        if (y & 1) {
            z = (z * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return z;
}

int main() {
    ll N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    ll factorial = 1;
    // N!を計算
    for (ll i = 1; i <= N; i++) {
        factorial = (factorial * i) % MOD;
    }
    // 確率の累積和を計算
    for (ll i = 1; i <= N; i++) {
        prob[i] = (calc_pow(i, MOD - 2) + prob[i - 1]) % MOD;
    }
    ll ans = 0;
    for (ll j = 0; j < N; j++) {
        ll sum_prob = 0;
        sum_prob = (sum_prob + prob[j + 1]) % MOD;
        sum_prob = (sum_prob + prob[N - j]) % MOD;
        sum_prob = (sum_prob - prob[1] + MOD) % MOD;  // 余計に足してる分を引く
        ans = (ans + (sum_prob * A[j]) % MOD) % MOD;
    }
    ans = (ans * factorial) % MOD;
    cout << ans << endl;
    return 0;
}