#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

typedef pair<ll, ll> P;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    if (N > M) swap(N, M);

    if (N == 1) {
        if (M == 1) cout << 1 << endl;
        else cout << M - 2 << endl;
    } else cout << (N-2)*(M-2) << endl;

    return 0;
}

