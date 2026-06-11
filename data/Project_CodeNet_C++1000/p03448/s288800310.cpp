#include <bits/stdc++.h>

using namespace std;

int A;
int B;
int C;
int X;


int bfs(int n, int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) return 0;
    if (n == 0) return 1;
    return bfs(n - 500, a - 1, b, c) + bfs(n - 100, a, b - 1, c) + bfs(n - 50, a, b, c - 1);
}


void solve() {
    int num = 0;
    for (int i = 0; i <= A; ++i) {
        for (int j = 0; j <= B; ++j) {
            for (int k = 0; k <= C; ++k) {
                if (500 * i + 100 * j + 50 * k == X) {
                    num++;
                }
            }
        }
    }
    printf("%d\n", num);
}

int main() {
    cin >> A >> B >> C >> X;
    solve();
    return 0;
}