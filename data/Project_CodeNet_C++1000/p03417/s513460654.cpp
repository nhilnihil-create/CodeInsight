#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, m, ans;
    cin >> n >> m;
    if (n >= 3 && m >= 3) ans = (n-2) * (m-2);
    else if (n == 1 && m == 1) ans = 1;
    else if (n == 1 || m == 1) ans = max(n, m) - 2;
    else ans = 0;
    cout << ans << endl;
}