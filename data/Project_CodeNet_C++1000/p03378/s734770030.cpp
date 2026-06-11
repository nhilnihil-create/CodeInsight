#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> A(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }
    auto it = lower_bound(A.begin(), A.end(), X);
    int toN = distance(it, A.end());
    int to0 = distance(A.begin(), it);
    cout << min(to0, toN) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
