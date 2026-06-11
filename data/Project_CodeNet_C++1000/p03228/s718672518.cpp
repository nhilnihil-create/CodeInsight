#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    for (int i = 0; i < K; ++i) {
        if (A % 2 == 1) A--;
        A /= 2;
        B += A;
        swap(A, B);
    }
    if (K % 2 == 1) swap(A, B);
    cout << A << " " << B << endl;
    return 0;
}
