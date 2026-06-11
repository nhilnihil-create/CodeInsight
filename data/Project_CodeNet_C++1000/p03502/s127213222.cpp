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
    if (N % findSumOfDigits(N) == 0) {
        printf("Yes");
    } else {
        printf("No");
    }
}

int main() {
    cin >> N;
    solve();
    return 0;
}