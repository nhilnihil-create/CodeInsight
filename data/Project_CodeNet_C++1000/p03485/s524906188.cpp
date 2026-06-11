#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int a, b;
    cin >> a >> b;

    int ans = (a + b) / 2;
    if ((a + b) % 2 == 1)
        ++ans;

    cout << ans << endl;

    return 0;
}
