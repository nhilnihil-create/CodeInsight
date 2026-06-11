#include"bits/stdc++.h"
using namespace std;
using ll = int64_t;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    if (A * B < N || A + B > N + 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> ans;
    ll num = 0;
    for (ll i = 0; i < B; i++) {
        ll tmp_num = min(N - num - (B - i - 1), A);
        for (ll j = 0; j < tmp_num; j++) {
            ans.push_back(N - num - tmp_num + j + 1);
        }
        num += tmp_num;
    }

    for (ll i = 0; i < N; i++) {
        printf("%lld%c", ans[i], " \n"[i == N - 1]);
    }
}