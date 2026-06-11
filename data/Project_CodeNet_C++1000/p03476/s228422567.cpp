#include <bits/stdc++.h>
using namespace std;
const int SZ = 1e5 + 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    vector<int> l(q), r(q);
    int high = 0;
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        high = max(high, r[i]);
    }

    bitset<SZ> prime;
    prime.flip();
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i <= high; i++) {
        if (prime[i]) {
            for (int j = i + i; j <= high; j += i) {
                prime[j] = false;
            }
        }
    }

    vector<int> cnt(high + 1);
    cnt[0] = 0;
    for (int i = 1; i <= high; i++) {
        cnt[i] = cnt[i - 1];
        if (prime[i] && prime[(i + 1) / 2]) {
            cnt[i]++;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << cnt[r[i]] - cnt[l[i] - 1] << '\n';
    }
    return 0;
}
