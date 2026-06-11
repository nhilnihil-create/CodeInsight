#include <iostream>

using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main () {
    int N;
    ll K;
    cin >> N >> K;

    ll A[N];
    rep(i, N) cin >> A[i];

    ll X = 0;
    for (int d = 39; d >= 0; d--) {
        int c = 0;
        for (int i = 0; i < N; i++) {
            c += (A[i] >> d) & 1;
        }
        X |= c < N - c ? (1ll << d) : 0;
    }

    for (int d = 39; d >= 0; d--) {
        ll k = (K >> d) & 1;
        ll b = (X >> d) & 1;
        if (k == 1 && b == 0) break;
        X ^= (k ^ b) << d;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i] ^ X;
    }

    cout << ans << endl;

    return 0;
}
