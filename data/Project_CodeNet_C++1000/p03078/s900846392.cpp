#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int X, Y, Z, K;

    cin >> X >> Y >> Z >> K;

    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);
    
    for(int i = 0; i < X; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < Y; i++) {
        cin >> B[i];
    }

    for(int i = 0; i < Z; i++) {
        cin >> C[i];
    }

    vector<ll> D(X * Y);

    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            D[i * Y + j] = A[i] + B[j];
        }
    }

    sort(D.begin(), D.end(), greater<ll>());

    int N = D.size();

    if(N > 3000) {
        N = 3000;
    }

    vector<ll> E(N * Z);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < Z; j++) {
            E[i * Z + j] = D[i] + C[j];
        }
    }

    sort(E.begin(), E.end(), greater<ll>());

    for(int i = 0; i < K; i++) {
        cout << E[i] << endl;
    }
}