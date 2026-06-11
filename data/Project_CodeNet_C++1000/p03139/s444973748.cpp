#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, A, B;
    cin >> N >> A >> B;

    ll a1 = min(A,B);
    ll a2 = max(A+B-N,0LL);
    cout << a1 << " " << a2 << "\n";
    return 0;
}

int main() {
    auto ans = solve();
    return 0;
}