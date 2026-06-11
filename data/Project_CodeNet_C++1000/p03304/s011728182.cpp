#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double solve() {
    ll N, M, D;
    cin >> N >> M >> D;
    ll c;
    if ( D > 0 ) {
        ll w = max(N-2*D, 0LL);
        c = (N-w) + w*2;
    } else {
        c = N;
    }
    double ans = c * (M-1) / (double)(N*N);
    return ans;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(16);
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}