#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 0, b = 0, c = 0, x = 0, kei = 0, cnt = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> x;

    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; ++k) {
                kei = (500 * i) + (100 * j) + (50 * k);
                if (x == kei)cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}