#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long N;
    cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return;
    }

    vector<long long> L(N + 1, 0LL);
    L[0] = 2;
    L[1] = 1;
    for (long long i = 2; i < N + 1; ++i) {
        L[i] = L[i - 1] + L[i - 2];
    }
    cout << L[N] << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
