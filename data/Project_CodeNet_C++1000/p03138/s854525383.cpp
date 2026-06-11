#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define BITS 40

int main()
{
    ll N, K; cin >> N >> K;
    vector<ll> A(N); for (auto& a : A) cin >> a;

    vector<int> bits(BITS);
    for (int i = 0; i < N; i++) {
        for (int b = 0; b < BITS; b++) {
            if (A[i] & (1LL << b)) bits[b]++;
        }
    }
    ll x = 0;
    for (int b = BITS-1; b >=0; b--) {
        if (bits[b] > N/2 == 0) {
            if ((x | (1LL << b)) <= K) {
                x |= (1LL << b);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += x^A[i];
    }
    cout << ans << endl;
}
