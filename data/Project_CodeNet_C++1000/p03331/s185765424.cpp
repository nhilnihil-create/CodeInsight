#include <bits/stdc++.h>
using namespace std;

int digit_sm(int K) {
    int res = 0;
    while (K > 0) res += K % 10, K /= 10;
    return res;
}

int main() {
    int N;
    cin >> N;
    int res = 1000000000;
    for (int A = 1; A < N; ++A) {
        int B = N - A;
        res = min(res, digit_sm(A) + digit_sm(B));
    }
    cout << res << endl;
    return 0;
}