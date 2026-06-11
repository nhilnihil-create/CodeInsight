#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int n, k;
    cin >> n >> k;

    double ans = 0;
    double ans_;
    int score;
    for ( int init = 1; init <= n; init++ ) {
        ans_ = 1.0 / n;
        score = init;
        while ( score < k ) {
            score *= 2;
            ans_ /= 2;
        }
        ans += ans_;
    }

    printf("%.10lf\n", ans);
    return 0;
}
