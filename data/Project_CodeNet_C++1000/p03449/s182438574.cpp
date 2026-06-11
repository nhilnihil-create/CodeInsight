#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    int N;
    cin >> N;

    int A[N];
    rep(i, N) cin >> A[i];
    int B[N];
    rep(i, N) cin >> B[i];

    rep(i, N - 1) A[i + 1] += A[i];
    rep(i, N - 1) B[N - 2 - i] += B[N - 1 - i];

    int ans = 0;
    rep(i, N) ans = max(ans, A[i] + B[i]);
    cout << ans << endl;

    return 0;
}
