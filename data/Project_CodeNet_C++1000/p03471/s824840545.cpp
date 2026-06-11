#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;
    int sum;
    bool end = false;

    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N - x; y++) {
            int money1000 = Y - (x * 10000 + y * 5000);
            //cout << 'x' << x << " y" << y << " money1000 " << money1000 << endl;
            if (money1000 % 1000 == 0 && money1000 / 1000 == N - (x + y)) {
                cout << x << ' ' << y << ' ' << N - (x + y) << endl;
                end = true;
            }
            if (end) break;
        }
        if (end) break;
    }
    if (!end) cout << "-1 -1 -1" << endl;
}