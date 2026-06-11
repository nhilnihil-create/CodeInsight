#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N; cin >> N;
    vector<ll> A(N), B(N);
    ll fixA = 0, fixB = 0;
    ll WaA = 0, WaB = 0;
    rep(i, N) cin >> A.at(i);
    rep(i, N) {
        cin >> B.at(i);
        WaA += A[i];
        WaB += B[i];
        if (A[i] < B[i]) { // You should check A first cause A can be updated
            ll d = (B[i] - A[i] + 1) / 2;
            fixA += d;
            A[i] += d * 2; // This update works right below here.
        }
        if (A[i] > B[i]) {
            ll d = A[i] - B[i];
            fixB += d;
            B[i] += d;
        }
    }
    if (WaA > WaB) {
        cout << "No" << endl;        
        return 0;
    }

    if (fixA >= fixB) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
