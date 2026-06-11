#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll A, B;
    cin >> A >> B;

    ll ans = 0;
    vector<ll> N(4, -1);
    vector<bool> repeat(4, false);
    if (B - A < 12) {
        for (ll i = A; i <= B; ++i) {
            ans ^= i;
        }
    } else {
        rep(i, 12) {
            ans ^= A + i;
            if (N[i % 4] == ans) repeat[i % 4] = true;
            N[i % 4] = ans;
        }

        int a = (B - A) % 4;
        if (repeat[a] == true)
            ans = N[a];
        else
            ans = N[(a + 4 - 1) % 4] ^ B;
    }
    cout << ans << endl;
}