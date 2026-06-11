#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    bool can = true;
    int pt = 0, px = 0, py = 0; // 前回の時刻と座標
    for (int i = 0; i < N; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        int T = t - pt, X = abs(x - px), Y = abs(y - py);
        if (T < X + Y) can = false;
        if (T % 2 != (X + Y) % 2) can = false;
        pt = t, px = x, py = y;
    }
    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
}