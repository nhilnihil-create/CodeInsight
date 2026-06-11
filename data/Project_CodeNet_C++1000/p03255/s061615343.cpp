#include <bits/stdc++.h>
using namespace std;

typedef __int128_t Long;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }
    long long ans = 1ll * x * n;
    Long nin = 1e18;
    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + as[i];
    }
    for (int k = 1; k <= n; k++) {
        Long cost = Long(5) * (sum[n] - sum[n - k]);
        for (int i = 1; n - k * i > 0; i++) {
            cost += (sum[n - k * i] - sum[max(0, n - k * (i + 1))]) * Long(2 * i + 3);
        }
        nin = min(nin, cost + 1ll * x * k);
    }
    cout << (long long) nin + ans << endl;
}