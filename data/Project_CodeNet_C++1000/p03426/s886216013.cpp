#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int h, w, d;
    cin >> h >> w >> d;
    vector<P> a(h*w+1);
    rep(i, h) {
        rep(j, w) {
            int x;
            cin >> x;
            a[x] = make_pair(i, j);
        }
    }

    vector<int> b(h*w+1, 0);
    for (int i = h * w + 1; i > 0; --i) {
        if (i + d > h * w + 1) continue;
        b[i] = abs(a[i].first - a[i + d].first) + abs(a[i].second - a[i + d].second) + b[i+d];
    }

    int q;
    cin >> q;
    rep(i, q) {
        ll ans = 0;
        int l, r;
        cin >> l >> r;
        cout << b[l] - b[r] << endl;
    }

    return 0;
}