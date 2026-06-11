#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main() {
    scanf("%d %d %d", &n, &a, &b);
    if (a + b - 1 > n || 1LL * a * b < n) printf("-1\n"), exit(0);
    vector<int> V;
    int m = n - a; n = 0;
    for (int i = 1; i <= a; i++) {
        int k = min(b - 1, m);
        V.push_back(n + k + 1);
        for (int j = 1; j <= k; j++) {
            V.push_back(n + k - j + 1), m--;
        }
        n += k + 1;
    }
    for (int x : V) printf("%d ", x);
    return 0;
}