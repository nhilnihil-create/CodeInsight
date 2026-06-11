#include "bits/stdc++.h"

using namespace std;

void Main() {
    int D, N;
    cin >> D >> N;

    int ans = 0;
    if (N < 100) {
        ans = N;
        for (int i = 0; i < D; ++i) {
            ans *= 100;
        }
        cout << ans << endl;
    }
    else {
        if (D == 0) {
            cout << 101 << endl;
        }
        else if (D == 1) {
            cout << 10100 << endl;
        }
        else {
            cout << 1010000 << endl;
        }
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
