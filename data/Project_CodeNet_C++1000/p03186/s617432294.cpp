#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll A, B, C;
    cin >> A >> B >> C;
    ll ans = min(C, A+B+1) + B;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}