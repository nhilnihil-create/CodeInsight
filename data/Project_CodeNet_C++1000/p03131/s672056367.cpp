#include <bits/stdc++.h>

using namespace std;

int main() {
    long long K, A, B;
    cin >> K >> A >> B;

    if (B - A <= 2) {
        cout << K + 1 << endl;
    } else {
        long long t = max(0LL, (K - (A - 1)) / 2);
        cout << A + (B - A) * t + (K - (A - 1)) % 2 << endl;
    }
    return 0;
}
