#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N, X;
    cin >> N >> X;

    vector<ll> x(N);
    for (ll i = 0; i < N; i++) {
        cin >> x[i];
    }

    //逆順にして考える
    reverse(x.begin(), x.end());

    //累積和を取る
    vector<ll> sum(N + 1, 0);
    for (ll i = 0; i < N; i++) {
        sum[i + 1] = sum[i] + x[i];
    }

    //オーバーフローをansより大きいかで判定して回避するので
    //LLONG_MAXぴったりではなく多少余裕を持たせて初期化する
    ll ans = LLONG_MAX / 2;

    //k := 往復する回数
    for (ll k = 1; k <= N; k++) {
        //先頭k個は初めて取るので距離の5倍がかかる
        ll s = X * (N + k) + sum[k] * 5;

        //先頭以外
        for (ll i = k; i < N; i += k) {
            s += (sum[min(i + k, N)] - sum[i]) * ((i / k) * 2 + 3);
            if (s >= ans) {
                break;
            }
        }
        ans = min(ans, s);
    }
    cout << ans << endl;
}