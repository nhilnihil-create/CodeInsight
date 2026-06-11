#include <bits/stdc++.h>
using namespace std;
int main () {
    long long A[2], K;
    cin >> A[0] >> A[1] >> K;
    for (int i = 0; i < K; i++) {
        if (A[i&1] & 1) A[i&1]--;
        A[i&1] /= 2;
        A[!(i&1)] += A[i&1];
    }
    printf("%lld %lld\n", A[0], A[1]);
}