#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int64_t ans = max({a, b, c}) * pow(2, k);
    ans += a + b + c - max({a, b, c});
    cout << ans << endl;
    return 0;
}