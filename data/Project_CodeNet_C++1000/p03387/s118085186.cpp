#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(3);
    for(auto &e : a) cin >> e;
    sort(a.begin(), a.end());
    // 2 3 6
    int d = a[2] - a[1];
    int ans = d;
    a[0] += d;
    a[1] += d;
    // 5 6 6
    d = a[1] - a[0];
    ans += (d + 1) / 2 + d % 2;
    cout << ans << '\n';
    return 0;
}
