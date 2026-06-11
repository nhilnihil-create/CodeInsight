#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int N;
int C[500] = {};
int S[500] = {};
int F[500] = {};

int solve(int i, int t) {
    int time = S[i];
    while (true) {
        if (time >= t)
            return time;
        time += F[i];
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; ++i) cin >> C[i] >> S[i] >> F[i];

    for (int i = 0; i < N - 1; ++i) {
        int t = S[i] + C[i];
        for (int j = i + 1; j < N - 1; ++j)
            t = solve(j, t) + C[j];
        cout << t << endl;
    }

    // 町N
    cout << 0 << endl;
}
