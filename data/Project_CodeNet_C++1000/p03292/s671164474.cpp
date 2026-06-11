#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

vector<ll> A(3);

int main() {
    rep(i, 3) cin >> A[i];

    vector<ll> v(3);
    rep(i, 3) v[i] = i;

    ll ans = INF;
    do {
        ll tmp = 0;
        tmp += abs(A[v[1]] - A[v[0]]);
        tmp += abs(A[v[2]] - A[v[1]]);

        ans = min(ans, tmp);

    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}