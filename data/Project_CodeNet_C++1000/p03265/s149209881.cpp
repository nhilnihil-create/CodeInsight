#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int difx = x2 - x1, dify = y2 - y1;
    int x3, x4, y3, y4;
    x3 = x2 - dify, y3 = y2 + difx;
    x4 = x1 - dify, y4 = y1 + difx;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}
