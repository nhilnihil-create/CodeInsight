#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << x2 + (y1 - y2) << " " << y2 - (x1 - x2) << " " << x1 + (y1 - y2) << " " << y1 - (x1 - x2) << endl;
    return 0;
}