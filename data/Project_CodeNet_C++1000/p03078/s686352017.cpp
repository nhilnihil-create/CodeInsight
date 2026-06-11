#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z), D, ans;
    rep(i, X) { cin >> A[i]; }

    rep(i, Y) { cin >> B[i]; }

    rep(i, Z) { cin >> C[i]; }

    rep(i, X) {
        rep(j, Y) { D.push_back(A[i] + B[j]); }
    }

    sort(all(D), greater<ll>());
    sort(all(C), greater<ll>());
    for (int i = 0; i < min(X * Y, 3001); i++) {
        rep(j, Z) { ans.push_back(D[i] + C[j]); }
    }

    sort(all(ans), greater<ll>());
    rep(i, K) { cout << ans[i] << endl; }
}