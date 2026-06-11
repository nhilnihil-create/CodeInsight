#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    rep(i, M) cin >> X[i];
    sort(all(X));
    vector<int> A(M - 1);
    int ans = 0;
    rep(i, M - 1) {
        A[i] = -abs(X[i] - X[i + 1]);
        ans -= A[i];
    }
    // cout << ans << endl;
    sort(all(A));
    // rep(i, M - 1) cout << A[i] << endl;
    
    rep(i, min(N - 1, M - 1)) ans += A[i];

    cout << ans << endl;
    return 0;
}
