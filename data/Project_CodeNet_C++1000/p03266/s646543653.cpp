#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<long long> cnt(k);
    for (int i = 1; i <= n; i++) cnt[i % k]++;
    long long ans = 0;
    for (int a = 0; a < k; a++) {
        int b = (k - a) % k, c = (k - a) % k;
        if ((b + c) % k) continue;
        ans += cnt[a] * cnt[b] * cnt[c];
    }
    cout << ans << endl;
    return 0;
}
