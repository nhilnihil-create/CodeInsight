/**
*    created: 24.06.2020 12:43:41
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int xd = x2 - x1;
    int yd = y2 - y1;
    int x3 = x2 - yd;
    int y3 = y2 + xd;
    int x4 = x3 - xd;
    int y4 = y3 - yd;
    cout << x3 << " " <<  y3 << " " <<  x4 << " " <<  y4 << endl;
    return 0;
}