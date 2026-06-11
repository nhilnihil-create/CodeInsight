#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    ll N, K;
    cin >> N >> K;
    vec<ll> A(N);
    rep(i, N) cin >> A[i];

    ll msk = 0;
    for (int i = 40; i >= 0; --i) {
        int cnt = 0;
        rep(j, N) if ((A[j] >> i) & 1)++ cnt;
        if (cnt * 2 <= N && (msk + (1LL << i)) <= K) {
            msk |= (1LL << i);
        }
    }
    int first1                            = 0;
    rep(i, 40) if (K & (1LL << i)) first1 = max(first1, i);

    ll msk2 = 0;
    for (int i = first1 - 1; i >= 0; --i) {
        int cnt = 0;
        rep(j, N) if ((A[j] >> i) & 1)++ cnt;
        if (cnt * 2 <= N) {
            msk2 |= (1LL << i);
        }
    }

    ll ans = 0;
    rep(i, N) ans += (msk ^ A[i]);

    ll ans2 = 0;
    rep(i, N) ans2 += (msk2 ^ A[i]);
    cout << max(ans,ans2) << endl;
}