#include <bits/stdc++.h>
using namespace std;

// 0回目 A,B,C -- A-B, B-C, C-A
// 1回目 B+C,A+C,A+B -- B-A, C-B, A-C
// 2回目 2A+B+C,A+2B+C,A+B+2C -- A-B, B-C, C-A
// 3回目 2A+3B+3C,3A+2B+3C,3A+3B+2C -- B-A, C-B, A-C
// ...
// n回目 nA, nB, nC -- nA-nB = A-B, nB-nC = B-C, nC-nA = C-A
// (n+1)回目 nB+nC, nA+nC, nA+nB -- nB-nA = B-A, nC-nB = C-B, nA-nC = A-C

int main() {
    long long A,B,C,K;
    cin >> A >> B >> C >> K;
    if(K&1LL) cout << B-A << endl;
    else cout << A-B << endl;
    return 0;
}