#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w; cin >> h >> w;
    int x, y; cin >> x >> y;
    int ans = h * w;
    ans += x * y;
    ans -= h * y;
    ans -= w * x;
    cout << ans << endl;
}