#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N; cin >> N;
    vector A(N, 0);
    int ma = INT32_MIN;
    int mi = INT32_MAX;
    int mai,mii;
    rep(i,N) {
        cin >> A.at(i);
        if (ma < A[i]) {
            ma = A[i];
            mai = i;
        }
        if (mi > A[i]) {
            mi = A[i];
            mii = i;
        }
    }
    if ((ll)ma * mi > 0LL) {
        cout << N-1 << endl;
        if (ma > 0)
            for (int i = 1; i < N; i++) cout << i << " " << i + 1 << endl;
        else
            for (int i = N; i > 1; i--) cout << i << " " << i - 1 << endl;
    } else {
        int ind;
        ind = (abs(ma) > abs(mi)) ? mai : mii;
        cout << 2 * N - 1 << endl;
        rep(i,N) cout << ind + 1 << " " <<  i + 1 << endl;
        if (ind == mai && ma > 0) 
            for (int i = 0; i < N - 1; i++) cout << i + 1 << " " << i + 2 << endl;
        else
            for (int i = N; i > 1; i--) cout << i << " " << i - 1 << endl;
    }
}
