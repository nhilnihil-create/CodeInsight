#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N, K; cin >> N >> K;
    if (K == 0) {
        cout << N*N << endl;
        return 0;
    }

    ll res = 0;
    for (ll b = 1; b <= N; b++) {
        res += max(0L, b-K) * (N/b);
        res += max(0L, N % b - K + 1);
    }
    cout << res << endl;
}
