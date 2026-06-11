#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b, c, ans = 0;
    cin >> a >> b >> c;

    if (a + b + 1 >= c)
    {
        ans = b + c;
    } else {
        ans = a + 1 + b + b;
    }
    cout << ans << endl;
    return 0;
}