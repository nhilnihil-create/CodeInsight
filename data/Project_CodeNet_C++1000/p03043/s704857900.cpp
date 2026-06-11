#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, k;
    cin >> n >> k;
    double ans = 0;
    rep(i, n+1) {
        if (i == 0) continue;
        int score = i;
        int cnt = 0;
        while (score < k) {
            score *= 2;
            cnt++;
        }
        ans += 1 / pow(2, cnt);
    }
    ans /= n;
    printf("%.9lf\n", ans);
}