#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    auto Check = [&](int k) {
        map<int, int> prv;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i - 1]) continue;
            if (k == 1) return false;
            int pos = a[i];
            while (!prv.empty() && prv.rbegin()->first > a[i]) prv.erase(prev(prv.end()));
            while (pos > 0 && prv.find(pos) != prv.end() && prv[pos] == k) pos--;
            if (pos == 0) return false;
            if (prv.find(pos) == prv.end()) prv[pos] = 2;
            else prv[pos]++;
            while (!prv.empty() && prv.rbegin()->first > pos) prv.erase(prev(prv.end()));
        }
        return true;
    };

    int ans = n;
    for (int d = 20; d >= 0; --d) {
        if (ans - (1 << d) <= 0) continue;
        if (Check(ans - (1 << d))) ans -= (1 << d);
    }
    printf("%d\n", ans);
    return 0;
}
