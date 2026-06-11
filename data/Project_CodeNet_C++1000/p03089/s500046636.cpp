#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n;
    cin >> n;
    vector < int > b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    deque < int > ans;
    while (!b.empty()) {
        int sz = int(b.size());
        for (int i = sz - 1; i >= 0; --i) {
            if (b[i] == i + 1) {
                ans.push_front(b[i]);
                b.erase(b.begin() + i);
                break;
            }
        }
        if (sz == int(b.size())) {
            cout << "-1\n";
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) 
        cout << ans[i] << '\n';
}
