#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int maxv = max({a, b, c});
    int ans = a + b + c;
    ans += maxv * pow(2, k) - maxv;

    cout << ans << endl;
    return 0;
}
