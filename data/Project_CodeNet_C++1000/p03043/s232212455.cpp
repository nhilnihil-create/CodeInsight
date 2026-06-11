#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    int n, k;
    cin >> n >> k;

    double ans = 0;
    for (int i = 1; i <= n; i++) {
        int point = i;
        double rate = (double)1/n;
        while (point < k) {
            point *= 2;
            rate *= (double)1/2;
        }
        ans += rate;
    }

    printf("%.20f\n", ans);
    return 0;
}
