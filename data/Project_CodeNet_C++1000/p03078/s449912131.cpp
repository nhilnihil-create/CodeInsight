#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const int MAX_X = 1e3 + 10;
const ll INF = 1e14;

int main(){
    ll X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y) , C(Z);
    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];

    vector<ll> D;
    priority_queue<ll> PQ;
    rep(i, X) rep(j, Y) D.push_back(A[i] + B[j]);
    sort(D.begin(), D.end(), greater<ll>());
    D.resize(min(X * Y, K));
    ll W = D.size();
    rep(i, W) rep(j, Z) PQ.push(D[i] + C[j]);

    rep(i, K){
        ll ans = PQ.top(); PQ.pop();
        cout << ans << endl;
    }

}
