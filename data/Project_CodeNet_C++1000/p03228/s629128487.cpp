#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    for (int k = 0; k < K; k++) {
        if (k % 2 == 0) {
            B += A / 2;
            A /= 2;
        } else {
            A += B / 2;
            B /= 2;
        }
    }
    cout << A << " " << B << endl;
}
