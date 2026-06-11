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

    int n;
    cin >> n;
    vi h(n);
    rep(i, n) cin >> h[i];

    int cnt = 0;
    int c = 0;
    while (c != n) {
        bool b = false;
        c = 0;
        for (int i = 0; i < n; i++) {
            if (h[i] != 0) {
                b = true;
                h[i]--;
            } else {
                if (b) {
                    cnt++;
                }
                b = false;
                c++;
            }

            if (i == n - 1) {
                if (b) {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
}