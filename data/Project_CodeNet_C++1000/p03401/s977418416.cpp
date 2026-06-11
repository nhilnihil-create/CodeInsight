#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    rep(i, n) scanf("%d", &a[i]);
    a.insert(a.begin(), 0);
    a.insert(a.end(), 0);

    int cost = 0;
    rep(i, n + 1) {
        cost += abs(a[i] - a[i + 1]);
    }

    for(int i = 1; i < n + 1; i++) {
        int ans = 0;
        ans = cost + abs(a[i + 1] - a[i - 1]) - abs(a[i] - a[i - 1]) - abs(a[i + 1] - a[i]);
        printf("%d\n", ans);
    }
    return 0;
}