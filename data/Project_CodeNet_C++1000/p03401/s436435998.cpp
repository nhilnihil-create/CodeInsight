#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 2);
    a[0] = 0, a[n + 1] = 0;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int max_cost = 0;
    rep(i, n + 1) max_cost += abs(a[i] - a[i + 1]);
    for(int i = 1; i <= n; i++){
        int ans = 0;
        ans = max_cost - (abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1])) + abs(a[i + 1] - a[i - 1]);
        printf("%d\n", ans);
    }
    return 0;
}