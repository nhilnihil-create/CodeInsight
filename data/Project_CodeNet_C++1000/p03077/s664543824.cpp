#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(5);
    ll mn = 1e15;
    for ( int i = 0; i < 5; i++ ) {
        cin >> A[i];
        mn = min(mn, A[i]);
    }
    ll ans = (N+mn-1)/mn + 4;
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}