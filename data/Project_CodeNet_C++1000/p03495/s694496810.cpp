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

    int n, k;
    cin >> n >> k;

    vi c(200000, 0);
    rep(i, n) {
        int t;
        cin >> t;
        c[t - 1]++;
    }
    int s = 0;
    rep(i, 200000) {
        if (c[i] > 0) {
            s++;
        }
    }

    sort(c.begin(), c.end());

    int cnt = 0;

    rep(i, 200000) {
        if (s <= k) {
            break;
        } else {
            if (c[i] > 0) {
                cnt += c[i];
                s--;
            }
        }
    }

    cout << cnt << endl;
}