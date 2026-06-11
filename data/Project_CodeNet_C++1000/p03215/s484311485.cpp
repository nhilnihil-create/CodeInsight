#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), sum(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    
    vector<long long> val;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            val.emplace_back(sum[j] - sum[i]);
        }
    }
    
    const int m = val.size();
    vector<bool> use(m, true);
    for (int b = 45; b >= 0; b--) {
        int cnt = 0;
        for (int i = 0; i < m; i++) if (use[i]) {
            if (val[i]&(1LL<<b)) cnt++;
        }
        if (cnt < k) continue;
        for (int i = 0; i < m; i++) if (use[i]) {
            if ((val[i]&(1LL<<b)) == 0) use[i] = false;
        }
    }
    
    long long ans = (1LL<<60) - 1;
    for (int i = 0; i < m; i++) {
        if (use[i]) ans &= val[i];
    }
    
    cout << ans << endl;
    return 0;
}