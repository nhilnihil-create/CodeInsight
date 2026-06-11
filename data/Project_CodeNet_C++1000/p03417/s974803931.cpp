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
    ll n, m;
    cin >> n >> m;

    ll res;
    if (n == 1 && m == 1) res = 1;
    else if (n == 1 || m == 1) res = n * m - 2;
    else if (n == 2 || m == 2) res = 0;
    else {
        res = n * m - (2 * (n + m) - 4);
    }

    cout << res << endl;

    return 0;
}