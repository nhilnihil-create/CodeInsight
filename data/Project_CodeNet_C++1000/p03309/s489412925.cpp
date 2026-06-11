#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (auto x : a) {
        ans += abs(x - a[n/2]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
