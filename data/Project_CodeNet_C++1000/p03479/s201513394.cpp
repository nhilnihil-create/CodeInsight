#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    Int x, y; cin >> x >> y;
    int ans = 0;
    while ( x <= y) {
        x = (Int)2 * x;
        ans++;
    }
    cout << ans << endl;
}