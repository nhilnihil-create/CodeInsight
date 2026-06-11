#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T, A, H;
    cin >> N;
    cin >> T >> A;
    cin >> H;
    double d = abs(A - (T - H * 0.006));
    int ans = 0;
    for (int i = 1; i < N; i++) {
        cin >> H;
        if (d > abs(A - (T - H * 0.006))) {
            d = abs(A - (T - H * 0.006));
            ans = i;
        }
    }
    cout << ans + 1 << endl;
}