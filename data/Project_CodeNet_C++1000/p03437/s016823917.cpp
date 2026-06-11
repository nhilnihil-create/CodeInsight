#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int x, y;
    cin >> x >> y;
    int64_t ans = 0;
    if (x % y == 0) ans = -1;
    else ans = x;
    cout << ans << endl;
}