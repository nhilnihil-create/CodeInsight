#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, M;
    cin >> N >> M;

    double p = pow(0.5, (double)M);
    int ans = (1900.0 * M + 100.0 * (N - M)) / p;
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
