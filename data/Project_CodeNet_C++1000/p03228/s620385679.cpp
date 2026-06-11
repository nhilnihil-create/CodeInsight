#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 1000000000;

int main() {
    int A, B, K;

    cin >> A >> B >> K;

    for (int i = 0; i < K; i++) {
        if (i % 2 == 0) {
            if (A % 2 == 1) {
                A -= 1;
            }
            B += A/2;
            A /= 2;
        } else {
            if (B % 2 == 1) {
                B -= 1;
            }
            A += B/2;
            B /= 2;
        }
    }

    cout << A << " " << B << endl;
}
