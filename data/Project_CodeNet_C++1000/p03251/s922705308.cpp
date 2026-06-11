#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    int n, m, x, y, a, b, mxx, mny;
    cin >> n >> m >> x >> y;
    mxx = x;
    for (int i = 0; i < n; i++) {
        cin >> a;
        mxx = max(mxx, a);
    }
    mny = y;
    for (int i = 0; i < m; i++) {
        cin >> b;
        mny = min(mny, b);
    }
    cout << (mny - mxx < 1 ? "War" : "No War");
}