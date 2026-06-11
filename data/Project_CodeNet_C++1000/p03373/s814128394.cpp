#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = 1e9;

    for (int i = 0; i <= max(x, y); i++) {
        ans = min(ans, i * c * 2 + max(0, x - i) * a + max(0, y - i) * b);
    }

    cout << ans;

    return 0;
}