#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> ketabit(42, 0);
    vector<ll> beki(42); beki[0] = 1;
    for (int i = 1; i < 42; i++) beki[i] = beki[i-1] * 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 42; j++) {
            if (A[i] & beki[j]) ketabit[j]++;
        }
    }

    ll X = 0, ans = 0;
    for (int i = 41; 0 <= i; i--) {
        if (X + beki[i] > K) {
            ans += beki[i] * ketabit[i];
        } else {
            if (2 * ketabit[i] < N) X += beki[i];
            ans += beki[i] * max(ketabit[i], N - ketabit[i]);
        }
    }
    cout << ans << endl;
}
