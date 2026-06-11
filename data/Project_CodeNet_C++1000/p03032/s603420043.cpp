#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, k;
    cin >> n >> k;
    vector < int > d(n);
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    int ans = 0; 
    for (int cur_k = 1; cur_k <= k; ++cur_k) {
        for (int deleted = 0; deleted <= cur_k / 2; ++deleted) {
            if (cur_k - deleted > n) 
                continue;
            else {
                int took = cur_k - deleted;
                for (int i = 0; i <= took; ++i) {
                    int sum = 0;
                    multiset < int > here;
                    for (int j = 0; j < i; ++j) {
                        sum += d[j];
                        here.insert(d[j]);
                    }
                    for (int j = n - 1; (n - 1 - j) < took - i; --j) {
                        sum += d[j];
                        here.insert(d[j]);
                    }
                    for (int j = 0; j < deleted; ++j) {
                        sum -= *here.begin();
                        here.erase(here.begin());
                    }
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << '\n';
}
