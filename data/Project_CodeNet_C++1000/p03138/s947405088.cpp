#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<int>> vv;
typedef pair<int, int> P;

// input
ll N, K;
vector<ll> A;

const int bn = 41;
vector<bitset<bn>> bit;
vector<ll> p;
ll w[bn][2];
bitset<bn> bk;


void input() {
    cin >> N >> K;
    A = vector<ll>(N);
    rep(i, N) cin >> A[i];
}


ll max_sum(int n) {
    ll ret = 0;
    rep(i, n) ret += max(w[i][0], w[i][1]);
    return ret;
}


ll solve(int i) {
    if (i == -1) return 0;
    if (bk.test(i)) {
        ll x = w[i][0] + max_sum(i);
        ll y = w[i][1] + solve(i - 1);
        return max(x, y);
    } else {
        return w[i][0] + solve(i - 1);
    }
}


int main() {
    input();
    bit = vector<bitset<bn>>(N);
    rep(i, N) bit[i] = bitset<bn>(A[i]);
    p = vector<ll>(bn);
    p[0] = 1;
    rep(i, bn - 1) p[i + 1] = 2 * p[i];
    rep(i, bn) {
        ll n = 0;
        rep(j, N) if (bit[j].test(i)) n++;
        w[i][0] = p[i] * n;
        w[i][1] = p[i] * (N - n);
    }
    bk = bitset<bn>(K);
    ll ans = solve(bn - 1);
    cout << ans << endl;
}
