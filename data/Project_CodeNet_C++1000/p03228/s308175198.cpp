#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    for (int i = 0; i < K; i++) {
        if (i % 2) {
            if (B % 2) {
                B--;
            }
            A += (B / 2);
            B = B / 2;
        }
        else {
            if (A % 2) {
                A--;
            }
            B += (A / 2);
            A = A / 2;
        }

    }

    cout << A << " " << B << endl;
}