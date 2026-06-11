#include <bits/stdc++.h>

using namespace std;

int N, Y;

void solve() {
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N - i; ++j) {
            if (Y == 10000 * i + 5000 * j + 1000 * (N - i - j)) {
                printf("%d %d %d \n", i, j, N - i - j);
                return;
            }
        }
    }
    printf("-1 -1 -1\n");
}

int main() {
    cin >> N >> Y;
    solve();
    return 0;
}