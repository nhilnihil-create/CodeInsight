#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];

    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    vector<ll> ABC;
    rep(a, X) 
        rep(b, Y) {
            if ((a + 1) * (b + 1) > K) break;
            rep(c, Z) {
                if ((a + 1) * (b + 1) * (c + 1) > K) break;
                ABC.push_back(A[a] + B[b] + C[c]);
            }
    }
    sort(ABC.rbegin(), ABC.rend());

    rep(i, K) cout << ABC[i] << endl;
    
    return 0;
}