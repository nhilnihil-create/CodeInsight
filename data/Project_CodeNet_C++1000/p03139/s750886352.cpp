#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); cout << fixed << setprecision(15);
    //freopen("input.txt", "r", stdin);
    int n, x, y;
    cin >> n >> x >> y;
    cout << min(x, y) << ' ' << max(0, x + y - n);
}
