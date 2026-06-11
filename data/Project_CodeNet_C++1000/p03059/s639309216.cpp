#include <bits/stdc++.h>

using namespace std;

int main() {

    int A, B, T;
    cin >> A >> B >> T;

    double t = T + 0.5;
    int tmp = A;
    int b = 0;
    while (tmp < t) {
        tmp += A;
        b += B;
    }
    cout << b << '\n';
    return 0;
}
