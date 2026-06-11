#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
// typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> F(n, vector<int>(10));
    rep(i, n) {
        rep(j, 10) {
            cin >> F[i][j];
        }
    }

    vector<vector<int>> P(n, vector<int>(11));
    rep(i, n) {
        rep(j, 11) {
            cin >> P[i][j];
        }
    }

    int res = -1 * INF;
    for (int bit = 1; bit < (1 << 10); ++bit) {
        int sum = 0;
        rep(i, n) {
            int t = 0;
            rep(j, 10) {
                if ((bit >> j) & F[i][j]) ++t;
            }
            sum += P[i][t];
        }
        chmax(res, sum);
    }

    cout << res << endl;

    return 0;
}