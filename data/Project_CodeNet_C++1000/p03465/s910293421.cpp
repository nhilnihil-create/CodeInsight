#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    int a[n], sum = 0;
    rep(i, n) cin >> a[i], sum += a[i];
    sum = sum + 1 >> 1;
    bitset<2003000> dp(1);
    rep(i, n) dp |= dp << a[i];
    while(!dp[sum])
        sum++;
    cout << sum;
}