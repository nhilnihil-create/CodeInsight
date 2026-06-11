#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647
// MAX O(n) 10^18

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // 図形から
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x3 = x2 - dy;
    int y3 = y2 + dx;
    int x4 = x3 - dx;
    int y4 = y3 - dy;

    cout << x3 << " " << y3 << " "  << x4 << " "  << y4 << endl;

    return 0;
}
