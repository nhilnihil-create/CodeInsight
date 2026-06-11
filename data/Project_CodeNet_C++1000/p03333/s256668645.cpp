#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> x = {0}, y = {0};
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        x.push_back(r);
        y.push_back(l);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end(), greater<int>());
    int64_t ans = 0, res = 0;
    for (int i = 0; i < min(x.size(), y.size()); ++i) {
        res += y[i];
        res -= x[i];
        ans = max(ans, res);
    }
    printf("%lld\n", ans * 2);
}
