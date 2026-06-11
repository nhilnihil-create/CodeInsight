#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    vector<int> X(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }
    vector<int> Y = X;
    sort(Y.begin(), Y.end());
    map<int, int> medians;
    for (int i = 0; i < N; ++i) {
        if (medians.count(Y[i]) > 0) {
            continue;
        }
        int n = 0;
        if (i < N / 2) {
            n = Y[N / 2];
        }
        else {
            n = Y[N / 2 - 1];
        }
        medians.insert(make_pair(Y[i], n));
    }

    for (int i = 0; i < N; ++i) {
        cout << medians[X[i]] << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
