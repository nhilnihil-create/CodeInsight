#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int ans = 0;
    for (int i = 0; i <= A; ++i) {
        for (int j = 0; j <= B; ++j) {
            for (int k = 0; k <= C; ++k) {
                if (500 * i + 100 * j + 50 * k == X) {
                    ++ans;
                }
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
