#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int cost;
    int min_cost = 2 * 100000 * 5000;
    for (int i = max(x, y)*2; i >= 0; i--) {
        if (i % 2 != 0) continue;

        cost = c * i + max(0, x - i/2) * a + max(0, y - i/2) * b;
        min_cost = min(min_cost, cost);
    }

    cout << min_cost << endl;
    return 0;
}
