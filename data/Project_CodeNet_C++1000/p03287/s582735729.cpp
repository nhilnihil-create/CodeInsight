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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    map<ll, ll> mp;
    REP(i, 1, n) {
        a[i] += a[i - 1];
    }

    rep(i, n) {
        mp[a[i] % m]++;
    }

    ll res = 0;
    for (auto x : mp) {
        ll t = x.second;
        if (x.first == 0) res += t;
        if (t >= 2) {
            res += t * (t - 1) / 2;
        }
    }

    cout << res << endl;

    return 0;
}