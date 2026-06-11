#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 100;
    for (int A = 1; A < N; A++) {
        int B = N - A;
        int sa = 0;
        int sb = 0;
        int a = A;
        int b = B;
        while (a) {
            sa += a % 10;
            a /= 10;
        }
        while (b) {
            sb += b % 10;
            b /= 10;
        }
        ans = min(ans, sa + sb);
    }
    cout << ans << endl;
}