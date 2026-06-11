#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;

    ll res = 0;
    // N = p * b + r とする
    // 0, 1, 2, ... b-1, 0, 1, 2...の繰り返し
    for(ll b = 1; b <= n; ++b) {
        if (k >= b) continue;
        ll p = n / b;
        ll r = n % b;
        res += p * max(0ll, b - k) + max(0ll, r + 1 - k);
    }

    // k = 0の時は、a = 0がn個分(b = 1...n)含まれるので除く
    if (k == 0) res -= n;
    cout << res << endl;

    return 0;
}