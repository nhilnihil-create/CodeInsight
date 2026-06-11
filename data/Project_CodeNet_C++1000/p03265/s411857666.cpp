#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x = x2 - x1;
    int y = y2 - y1;
    cout << x2 - y << " " << y2 + x << " " << x1 - y << " " << y1 + x << endl;
    return 0;
}
