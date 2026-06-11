#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    int D, X;
    cin >> D >> X;
    int n = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        int d = 1;
        while (d <= D) {
            ++n;
            d += A;
        }
    }
    cout << n + X << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
