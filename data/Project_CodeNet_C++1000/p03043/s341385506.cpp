#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K;
    cin >> N >> K;
    double ans = 0;
    for (int i=1; i<=N; i++) {
        int v = i;
        for (int t=0; t<20; ++t) {
            if (v>=K) {
                ans += 1.0 / (1<<t);
                break;
            }
            v *= 2;
        }
    }
    cout << fixed << setprecision(12);
    cout << ans/N << endl;
}
