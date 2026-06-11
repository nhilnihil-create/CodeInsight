#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N, M;
    cin >> N >> M;
    if (N == 1 && M == 1) {
        cout << 1 << endl;
    }
    else if (N <= 2 && M <= 2) {
        cout << 0 << endl;
    }
    else if (N == 1) {
        cout << (M - 2) << endl;
    }
    else if (M == 1) {
        cout << (N - 2) << endl;
    }
    else {
        cout << (N - 2) * (M - 2) << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
