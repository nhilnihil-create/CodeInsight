#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    double ans = 0;
    for (int i = 1; i <= N; i++) {
        int x = i;
        double score = 1.0 / N;
        while (x < K) {
            score /= 2.0;
            x *= 2;
        }
        ans += score;
    }

    cout << fixed << setprecision(15) << ans << endl;
}