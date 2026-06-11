#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9;

int main() {
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    auto b = a;
    sort(begin(b), end(b));
    b.erase(unique(begin(b), end(b)), end(b));

    int ans = inf;
    vector<bool> ban(n);
    for(const auto mini : b) {
        vector<int> c;
        for(int i = 0; i < n; ++i) {
            if(ban[i]) continue;
            vector<int> tmp;
            while(i < n && !ban[i]) {
                tmp.push_back(a[i++]);
            }
            sort(begin(tmp), end(tmp));
            for(int j = 0; j < (int)tmp.size() - k + 1; ++j) {
                c.push_back(tmp[j]);
            }
        }

        if((int)c.size() < q) break;

        sort(begin(c), end(c));
        ans = min(ans, c[q - 1] - mini);
        for(int i = 0; i < n; ++i) {
            if(a[i] != mini) continue;
            ban[i] = true;
        }
    }

    cout << ans << endl;
}
