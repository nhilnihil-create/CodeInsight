#include <bits/stdc++.h>
using namespace std;


void solve () {
    int n;
    cin >> n;
    vector<unordered_map <int, int>> a(2);
    for  (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i & 1][x]++;
    }
    vector<pair<int, int>> even, odd;
    even.push_back({0, 0});
    odd.push_back({0, 0});
    for (auto p : a[0]) {
        even.push_back({p.second, p.first});
    }
    for (auto p : a[1]) {
        odd.push_back({p.second, p.first});
    }
    sort(even.begin(), even.end(), greater<pair<int, int>>());
    sort(odd.begin(), odd.end(), greater<pair<int, int>>());
    int ans = 1e5;
    n /= 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int plus = 0;
            if(even[i].second == odd[j].second) {
                plus = 1e5;
            }
            ans = min (ans, plus + (n - even[i].first) + (n - odd[j].first));
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
