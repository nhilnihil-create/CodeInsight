#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, H, W;
    cin >> N >> H >> W;
    ll ans = (N-H+1)*(N-W+1);
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}