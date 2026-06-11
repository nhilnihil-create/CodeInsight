#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    vector<long long> sum;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            long long s = 0;
            for (int i = l; i <= r; i++) {
                s += a.at(i);
            }
            sum.push_back(s);
        }
    }

    int len = n * (n + 1) / 2;
    long long ans = 0;
    vector<bool> to_use(sum.size(), true);
    for (int digit = 45; digit >= 0; digit--) {
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (!to_use.at(i)) continue;

            if (sum.at(i) & (1ll << digit)) cnt++;
        }
        if (cnt >= k) {
            ans += 1ll << digit;

            for (int i = 0; i < len; i++) {
                if (!(sum.at(i) & (1ll << digit))) to_use.at(i) = false;
            }
        }
    }

    cout << ans << endl;
}