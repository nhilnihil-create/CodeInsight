#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<int64_t> A(X), B(Y), C(Z), D(X*Y), E(3000*Z);
    for(int i=0; i<X; i++) {
        cin >> A[i];
    }
    for(int i=0; i<Y; i++) {
        cin >> B[i];
    }
    for(int i=0; i<Z; i++) {
        cin >> C[i];
    }

    for(int i=0; i<X; i++) {
        for(int j=0; j<Y; j++) {
            D[i*Y+j] = A[i] + B[j];
        }
    }

    sort(D.rbegin(), D.rend());
    for(int i=0; i<min(3000, X*Y); i++) {
        for(int j=0; j<Z; j++) {
            E[i*Z+j] = D[i] + C[j];
        }
    }
    sort(E.rbegin(), E.rend());

    for(int i=0; i<K; i++) {
        cout << E[i] << endl;
    }
    return 0;
}
