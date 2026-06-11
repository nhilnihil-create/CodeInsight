#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

int main() {
    unordered_map<int, int> odd, even;
    int n;
    cin >> n;
    rep(i, 0, n) {
        int x;
        cin >> x;
        if (i & 1) odd[x]++;
        else even[x]++;
    }
    int half = n / 2;
    map<int, vector<int>> a, b;
    for (auto it : odd) a[it.second].push_back(it.first);
    for (auto it : even) b[it.second].push_back(it.first);
    if (a.rbegin()->second.size() > 1 || b.rbegin()->second.size() > 1) {
        cout << half - a.rbegin()->first + half - b.rbegin()->first;
        return 0;
    }
    if (a.rbegin()->second[0] != b.rbegin()->second[0]) {
        cout << half - a.rbegin()->first + half - b.rbegin()->first;
        return 0;
    }

    int ans = int(1e9);
    if (a.size() > 1) {
        auto it = next(a.rbegin());
        ans = min(ans, half - it->first + half - b.rbegin()->first);
    }

    if (b.size() > 1) {
        auto it = next(b.rbegin());
        ans = min(ans, half - it->first + half - a.rbegin()->first);
    }

    if (a.size() == 1 && b.size() == 1) ans = min(ans, half);
    cout << ans << '\n';
}