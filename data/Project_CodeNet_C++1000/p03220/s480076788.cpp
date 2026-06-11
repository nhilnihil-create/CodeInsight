#include <bits/stdc++.h>

using namespace std;

int N;
int T;
int A;
int H[1000];

void solve() {
    double min = 100000;
    int min_i = 0;
    for (int i = 0; i < N; i++) {
        if (min > abs(A - T + 0.006 * H[i])) {
            min = abs(A - T + 0.006 * H[i]);
            min_i = i + 1;
        }
    }
    printf("%d\n", min_i);
    return;
}

int main() {
    cin >> N;
    cin >> T >> A;
    for (int i = 0; i < N; i++) cin >> H[i];
    solve();
    return 0;
}