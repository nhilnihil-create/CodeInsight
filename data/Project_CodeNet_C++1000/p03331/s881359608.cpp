#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N;
    int sum;
    int min = INFINITY;
    for (int i = 1; i < N; i++) {
        sum = 0;
        A = i;
        while (A > 0) {
            sum += A % 10;
            A /= 10;
        }
        B = N - i;
        while (B > 0) {
            sum += B % 10;
            B /= 10;
        }
        if (sum < min) min = sum;
    }
    cout << min << endl;
}
