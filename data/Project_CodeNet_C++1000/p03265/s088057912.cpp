#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
int _x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4;

int main() {
    cin >> _x1 >> _y1 >> _x2 >> _y2;
    int x = _x2 - _x1;
    int y = _y2 - _y1;
    _x3 = _x2 - y ;
    _y3 = _y2 + x;
    _x4 = _x3 - x;
    _y4 = _y3 - y;
    cout << _x3 << ' ' << _y3 << ' ' << _x4 << ' ' << _y4 << endl;
    return 0;
}
