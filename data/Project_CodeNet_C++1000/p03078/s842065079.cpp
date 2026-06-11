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

    vector<ll> AB;
    rep(i, X) rep(j, Y) AB.push_back(A[i] + B[j]);

    sort(AB.rbegin(), AB.rend());

    vector<ll> ABC;
    rep(i, min(K, (int)AB.size())) rep(j, Z) ABC.push_back(AB[i] + C[j]);

    sort(ABC.rbegin(), ABC.rend());

    rep(i, K) cout << ABC[i] << endl;
    
    return 0;
}