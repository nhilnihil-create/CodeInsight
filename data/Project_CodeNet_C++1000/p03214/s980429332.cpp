#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 1000000000;

int main() {
    int N, A[100];
    int ans;
    double avr = 0;
    double diff;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        avr += A[i];
    }
    avr /= N;

    diff = avr;
    for (int i = 0; i < N; i++) {
        if (diff > (abs(A[i]-avr))) {
            diff = abs(A[i]-avr);
            ans = i;
        }
    }

    cout << ans << endl;
}
