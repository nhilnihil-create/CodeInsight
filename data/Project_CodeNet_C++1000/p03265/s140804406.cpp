#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll x1, y1, x2, y2;
    ll diff[2];
    ll cords[2][2];
    cin >> x1 >> y1 >> x2 >> y2;
    diff[0] = x2 - x1;
    diff[1] = y2 - y1;
    cords[0][0] = x2 - diff[1];
    cords[0][1] = y2 + diff[0];
    cords[1][0] = x1 - diff[1];
    cords[1][1] = y1 + diff[0];
    cout << cords[0][0] << ' ' << cords[0][1] << ' ' << cords[1][0] << ' ' << cords[1][1] << endl;
    return 0;
}
