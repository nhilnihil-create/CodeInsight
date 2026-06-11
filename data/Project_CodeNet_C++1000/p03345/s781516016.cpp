#include <bits/stdc++.h>
using namespace std;

int main() {
    long long A, B, C, K;
    cin >> A >> B >> C >> K;
    if (abs(A - B) >= pow(10, 18)) {
        cout << "Unfair" << endl;
    } else {
        if (K % 2 == 1) {
            printf("%lld\n", -(A - B));
        } else {
            printf("%lld\n", A - B);
        }
    }
    return 0;
}