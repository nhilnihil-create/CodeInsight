#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int x[100000];
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> x[i];

    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }

    sort(x, x + m);
    int dis[99999];
    for (int i = 0; i < m - 1; i++) {
        dis[i] = abs(x[i + 1] - x[i]);
    }

    sort(dis, dis + m - 1);
    int ans = 0;
    for (int i = 0; i < m - n; i++) ans += dis[i];

    cout << ans << endl;
}