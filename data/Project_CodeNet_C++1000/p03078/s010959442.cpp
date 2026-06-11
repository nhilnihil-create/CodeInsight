#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
// __uint128_t




int main(){
    ll X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    for(int i = 0; i < X; i++) cin >> A[i];
    for(int i = 0; i < Y; i++) cin >> B[i];
    for(int i = 0; i < Z; i++) cin >> C[i];
    priority_queue<ll> E, ANS;
    sort(C.rbegin(), C.rend());
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++) E.push(A[i]+B[j]);
    }
    for(int _ = 0; _ < min(X*Y, K); _++){
        ll e = E.top(); E.pop();
        for(int i = 0; i < min(Z, K); i++){
            ANS.push(e+C[i]);
        }
    }
    for(int i = 0; i < K; i++){
        ll x = ANS.top(); ANS.pop();
        cout << x << endl;
    }


}