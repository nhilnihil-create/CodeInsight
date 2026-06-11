#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    bool yes = false;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (4 * i + 7 * j == N) {
                yes = true;
                break;
            }
        }
        if (yes) {
            break;
        }
    }
    cout << (yes ? "Yes" : "No") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
