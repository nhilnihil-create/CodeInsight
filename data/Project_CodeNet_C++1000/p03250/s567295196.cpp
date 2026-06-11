#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    if (a >= b && a >= c)
        ans = a * 10 + b + c;
    else if (b >= a && b >= c)
        ans = b * 10 + a + c;
    else
        ans = c * 10 + a + b;

    cout << ans << endl;
    return 0;
}
