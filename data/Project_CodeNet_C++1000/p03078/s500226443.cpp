#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using namespace std;

vector<ll> AB;
vector<ll> ans;

int main() {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);
    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];
    sort(rall(C));

    rep(x, X) rep(y, Y) {
        AB.push_back(A[x] + B[y]);
    }
    sort(rall(AB));

    rep(i, min(X*Y, K)) rep(z, min(K, Z)) {
        ans.push_back(AB[i] + C[z]);
    }
    sort(rall(ans));

    rep(i, K) cout << ans[i] << endl;
}
