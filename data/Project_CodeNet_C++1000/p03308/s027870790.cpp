#include <bits/stdc++.h>

using namespace std;

int N;
int A[100];

void solve() {
    int max = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            if (abs(A[i] - A[j]) > max) max = abs(A[i] - A[j]);
        }
    }
    printf("%d\n", max);
    return;
}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    solve();
    return 0;
}