#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <typename T>
T _gcd(T a, T b) {
    return b ? _gcd(b, a % b) : a;
}

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

void f(ll n) {
    for (ll q = 1; q <= 3500; q++) {
        for (int p = q; p <= 3500; p++) {
            ll s = n * p * q;
            ll t = 4 * p * q - n * (p + q);

            if (t <= 0)
                continue;

            if (s % t == 0) {
                cout << p << " " << q << " " << s / t << endl;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    f(n);
}