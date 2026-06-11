#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;

int main() {

    Int N;
    cin >> N;
    vector<Int> A(N);
    rep(i,N) cin >> A[i];

    vector<Int> L(N), R(N);

    L[0] = A[0];
    rep1(i,N-1) L[i] = __gcd(L[i-1],A[i]);

    R[N-1] = A[N-1];
    rep1(i,N-1) R[N-1-i] = __gcd(R[N-i], A[N-1-i]);

    Int MAX = R[1];
    rep1(i,N-2) {
        MAX = max(MAX, __gcd(L[i-1], R[i+1]));
    }
    MAX = max(MAX, L[N-2]);

    cout << MAX << endl;

    return 0;
}
