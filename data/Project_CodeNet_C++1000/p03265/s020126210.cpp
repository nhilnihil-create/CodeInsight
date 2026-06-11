#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

void solve() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x_diff = x2 - x1;
    int y_diff = y2 - y1;

    int x3 = x2 - y_diff;
    int y3 = y2 + x_diff;
    int x4 = x1 - y_diff;
    int y4 = y1 + x_diff;

    printf("%d %d %d %d\n", x3, y3, x4, y4);
}

int main() {
    solve();

    return 0;
}
