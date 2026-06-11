#include <bits/stdc++.h>

using namespace std;

int N;

void solve() {
    int num = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (i * 4 + j * 7 == N) {
                num++;
                break;
            }
        }
    }
    if (num > 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

}

int main() {
    cin >> N;
    solve();
    return 0;
}