#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll K, A, B;
    cin >> K >> A >> B;
    if (B - A <= 2) {
        cout << 1 + K << endl;
        return 0;
    }
    if (1 + K <= A) {
        cout << 1 + K << endl;
        return 0;
    }
    ll left_time = K - (A - 1);
    ll ans = A + (left_time / 2) * (B - A);
    if (left_time % 2 == 1) {
        ans += 1;
    }
    cout << ans << endl;
}
