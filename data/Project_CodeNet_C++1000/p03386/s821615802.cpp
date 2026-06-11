#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int A, B, K; cin >> A >> B >> K;
    if (B - A + 1 < K * 2) {
        int N = B - A + 1;
        rep(i, N) cout << A + i << endl;
    }
    else {
        rep(i, K) cout << (A + i) << endl;
        rep(i, K) cout << (B - K + i + 1) << endl;
    }
    return 0;
}