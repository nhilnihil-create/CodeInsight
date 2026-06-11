#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main() {
    ll N;
    cin >> N;

    vector<ll> values(N, 0);
    REP(i, N) {
        cin >> values[i];
    }
    sort(values.begin(), values.end());

    ll diffMax = abs(values[N - 1] - values[0]);
    cout << diffMax << endl;
    return 0;
}