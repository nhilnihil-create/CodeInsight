#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    set<array<int, 2>> s;
    for (auto p : mp) {
        s.insert({p.second, p.first});
    }
    int sz = (int) s.size();
    int i = max(0, sz - k);
    int ans = 0;
    for (auto x : s) {
        if(!i) {
            break;
        }
        ans += x[0];
        i--;
    }
    cout << ans;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
