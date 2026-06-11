#include <bits/stdc++.h>

using namespace std;

int N;
int m[100];
int X;

void solve() {
    int min = m[0];
    for (int i = 0; i < N; ++i) {
        X -= m[i];
        if (min > m[i]) {
            min = m[i];
        }
    }
    printf("%d\n", X / min + N);
}

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; ++i) cin >> m[i];
    solve();
    return 0;
}