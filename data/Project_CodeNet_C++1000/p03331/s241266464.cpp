#include <bits/stdc++.h>

using namespace std;

int N;

int findSumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    int min = 10000000;

    for (int i = 1; i < N; ++i) {
        if (min > findSumOfDigits(i) + findSumOfDigits(N - i)) {
            min = findSumOfDigits(i) + findSumOfDigits(N - i);
        }
    }
    printf("%d\n", min);
}

int main() {
    cin >> N;
    solve();
    return 0;
}