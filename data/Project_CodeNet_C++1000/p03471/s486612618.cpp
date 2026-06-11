#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, Y;
    cin >> N >> Y;

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N - i; ++j) {
            int k = N - i - j;
            if (k * 10000 + j * 5000 + i * 1000 == Y) {
                cout << k << " " << j << " " << i << endl;
                return;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
