#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    vector<int> a;
    for (auto p : mp) {
        a.push_back(p.second);
    }
    int total = (int) mp.size();
    sort(a.begin(), a.end());
    int ans = 0;
    for (auto x : a) {
        if (total <= k) {
            cout << ans;
            return 0;
        }
        total--;
        ans += x;
    }
    return 0;
}
