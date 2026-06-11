#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;

    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            if (N - x - y < 0) break;
            int total = 10000 * x + 5000 * y + 1000 * (N - x - y);

            if (total == Y) {
                cout << x << " " << y << " " << (N - x - y) << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}