#include <bits/stdc++.h>
using namespace std;

int main() {
    long long K, A, B;
    cin >> K >> A >> B;

    long long ans = 1;
    if (B - A <= 2 || K <= A - 1) {
        ans += K;
    } else {
        K -= A - 1;
        ans += A - 1;
        ans += (B - A) * (K / 2);
        ans += K % 2;
    }

    cout << ans << endl;
}