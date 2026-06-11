#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t N, D, X;
    cin >> N >> D >> X;
    vector<int64_t> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    int64_t res = X;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            if (j == 0) res++;
            else if (j == 1 && A.at(i) + 1 <= D) res++;
            else if (j * A.at(i) + 1 <= D) res++;
        }
    }
    cout << res << endl;
}