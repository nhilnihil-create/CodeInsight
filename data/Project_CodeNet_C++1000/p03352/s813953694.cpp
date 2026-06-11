#include "bits/stdc++.h"

using namespace std;

int powi(int x, int y) {
    int ret = 1;
    for (int i = 0; i < y; ++i) {
        ret *= x;
    }
    return ret;
}

void Main() {
    int X;
    cin >> X;

    int ans = 1;
    for (int i = 1; i <= X; ++i) {
        for (int j = 2; j <= 10; ++j) {
            int p = powi(i, j);
            if (p <= X) {
                ans = max(ans, p);
            }
            else {
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
