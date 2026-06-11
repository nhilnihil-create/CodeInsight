#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    if (n >= 3 && m >= 3) {
        cout << (n - 2) * (m - 2) << endl;
    } else {
        if (n == 2 || m == 2) {
            cout << 0 << endl;
        } else {
            if (n == 1 && m == 1) {
                cout << 1 << endl;
            } else {
                if (n < m) {
                    cout << max(m - 2, 0LL) << endl;
                } else {
                    cout << max(n - 2, 0LL) << endl;
                }
            }
        }
    }
}