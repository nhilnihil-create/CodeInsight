#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    long long int A, B, K; cin >> A >> B >> K;
    for (int i = 0; i < K; i++) {
        if (i % 2 == 0) {
            if (A % 2 != 0) A--;
            B += A / 2;
            A /= 2;
        }
        else {
            if (B % 2 != 0) B--;
            A += B / 2;
            B /= 2;
        }
    }
    printf("%lld %lld", A, B);
}
