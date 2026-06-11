#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    int ans = abs(a[n - 1] - w);
    if(n > 1) ans = max(ans, abs(a[n - 2] - a[n - 1]));
    cout << ans << '\n';
    return 0;
}
