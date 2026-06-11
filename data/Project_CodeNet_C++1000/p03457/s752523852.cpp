#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1e18;
# define len(x) ((int)(x).size())
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define foreps(i, m, n) for(int i = m;i < n;i++)
# define ALL(x) (x).begin(), (x).end()
# define rall(x) (x).rbegin(), (x).rend()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ll N; cin >> N;
    vector<ll> T(N + 1, 0), X(N + 1, 0), Y(N + 1, 0);
    reps(i, N) {
        cin >> T[i] >> X[i] >> Y[i];
    } 

    bool ans = true;
    for (ll i = 0; i < N; i++) {
        ll dt = T[i + 1] - T[i], distance = abs(X[i + 1] - X[i]) + abs(Y[i + 1] - Y[i]);
        if (dt < distance) ans = false;
        if (dt % 2 != distance % 2) ans = false;
    }
    cout << (ans ? "Yes" : "No") << endl;
}