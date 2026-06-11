#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll LINF = 1e18;
const int INF = 1e9;
const ll MOD = 1000000007;

int main(){

    int x1, x2, x3, x4;
    int y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2;

    int dx, dy;
    dx = x2 - x1;
    dy = y2 - y1;

    x3 = x2 - dy;
    y3 = y2 + dx;
    x4 = x1 - dy;
    y4 = y1 + dx;

    cout << x3 << " " <<  y3 << " " << x4 << " " << y4 << endl;

    return 0;
}