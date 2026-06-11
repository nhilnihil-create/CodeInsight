#include <bits/stdc++.h>
# define rep(i, n) for (ll i = 0; i < (n); i++)
# define reps(i, n) for (ll i = 1; i <= (n); i++)
# define foreps(i, m, n) for (ll i = (m); i < (n); i++)
# define len(x) ((int)(x).size())
# define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

int main() {
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> C = A;
    sort(all(C));

    ll range = N / 2 - 1;
    rep(i, N) {
        if (A[i] <= C[range]) cout << C[range + 1] << endl;
        else cout << C[range] << endl;
    }
}