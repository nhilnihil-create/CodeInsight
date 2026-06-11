// Digits Sum
#include <iostream>
#include <algorithm>
using namespace std;

int findSumOfDigits(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int N;
    int mi_sum = 1 << 30;
    cin >> N;
    for (int A = 1; A < N; ++A) {
        int B = N - A;
        int su = findSumOfDigits(A) + findSumOfDigits(B);
        mi_sum = min(mi_sum, su);
    }
    cout << mi_sum << endl;
}