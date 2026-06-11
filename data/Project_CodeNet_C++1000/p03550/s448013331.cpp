#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N,Z,W; cin >> N >> Z >> W;
    vector A(N,0);
    rep(i,N) cin >> A.at(i);
    if (N == 1) {
        cout << abs(A[0] - W) << endl;
    } else
        cout << max(abs(A[N-1] - W), abs(A[N-1]-A[N-2])) << endl;
}
