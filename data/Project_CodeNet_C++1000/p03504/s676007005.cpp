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

const int MAX_N = 100010;
vector<int> a(MAX_N, 0);


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
    rep(i, n) {
        int s, t, x;
        cin >> s >> t >> x;
        s, t;
        a[s-1]++;
        a[t]--;
    }

    REP(i, 1, MAX_N) {
        a[i] += a[i-1];
    }
    int ans = 0;
    rep(i, MAX_N) {
        if (a[i] > c) a[i] = c;
        chmax(ans, a[i]);
    }

    cout << ans << endl;

    return 0;
}