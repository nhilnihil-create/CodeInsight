#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int a[3];
    rep(i, 3) cin >> a[i];
    sort(a, a + 3);

    if (a[0] == a[1])
        cout << a[2];
    else
        cout << a[0];
    cout << endl;

    return 0;
}
