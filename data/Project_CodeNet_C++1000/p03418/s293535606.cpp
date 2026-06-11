#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vll = vector<long long>;

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    long long cnt = 0;
    if (k > 0) {
        for (int i = k + 1; i <= n; i++) {
            int t = n - (n % i);

            cnt += t / i * (i - k) + max(0, n % i - k + 1);
        }
    } else {
        for (int i = 1; i <= n; i++) {
            cnt += n;
        }
    }

    cout << cnt << endl;
}