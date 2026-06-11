#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, K; cin >> n >> K;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    vector<long long> acc(n + 1);
    for (int i = 0; i < n; i++) acc[i + 1] = acc[i] + a[i];
    long long ans = 0;
    for (int k = 40; k >= 0; k--) {
        ans |= 1LL << k;
        int cnt = 0;
        for (int l = 0; l < n; l++) for (int r = l + 1; r <= n; r++) {
            if (((acc[r] - acc[l]) & ans) == ans) cnt++;
        }
        if (cnt < K) ans ^= 1LL << k;
    }
    cout << ans << endl;
    return 0;
}
