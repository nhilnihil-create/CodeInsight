#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll X, Y, Z, K;
vector<ll> A, B, C;

int main() {
    cin >> X >> Y >> Z >> K;
    A.resize(X);
    B.resize(Y);
    C.resize(Z);

    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];

    // K番目までの美味しさの和を大きい順でだす
    // A, B
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());

    vector<ll> v;
    rep(i, A.size()) {
        rep(j, B.size()) {
            v.push_back(A[i] + B[j]);
        }
    }
    sort(v.rbegin(), v.rend());

    vector<ll> v2;
    ll target = min((ll)3000, (ll)v.size());
    rep(i, target) {
        rep(j, C.size()) {
            v2.push_back(v[i] + C[j]);
        }
    }
    sort(v2.rbegin(), v2.rend());

    rep(i, K) {
        cout << v2[i] << endl;
    }

    // rep(i, K) {
    //     ll ans = v[i] + C[i];
    //     cout << ans << endl;
    // }
}