#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;

    ll ans = n == 1 || m == 1 ? max(1ll, n * m - 2) : (n - 2) * (m - 2);

    cout << ans << endl;
    return 0;
}
