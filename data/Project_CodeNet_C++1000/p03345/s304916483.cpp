#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, c, k;

void solve() {
    cin >> a >> b >> c >> k;
    int res = a - b;
    if(k & 1) cout << -res << "\n";
    else cout << res << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

}