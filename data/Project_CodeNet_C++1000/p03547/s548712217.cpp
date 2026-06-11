#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;

int main() {
    char X, Y;
    cin >> X >> Y;
    char ans;
    if (X > Y) ans = '>';
    else if (X < Y) ans = '<';
    else ans = '=';
    cout << ans << endl;
    return 0;
}