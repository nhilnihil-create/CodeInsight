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
    vector<vector<ll>> a(n, vector<ll>(3));
    rep(i, n) {
        rep(j, 3) {
            cin >> a[i][j];
        }
    }


    ll res = -1 * LINF;
    rep(i, 8) {
        vector<ll> vec;
        for (int j = 0; j < n; ++j) {
            ll s = 0;
            rep(k, 3) {
                if ((i / (1 << k)) % 2 == 0) s += a[j][k];
                else s -= a[j][k];
            }
            vec.push_back(s);
        }
        sort(vec.begin(), vec.end(), greater<ll>());
        ll sum = 0;
        rep(j, m) sum += vec[j];
        chmax(res, sum);
    }

    cout << res << endl;

    return 0;
}