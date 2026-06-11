#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 998244353;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    ll ans = 0;
    int mi = INF;
    rep(i, n) {
        int a;
        cin >> a;
        if(a < 0) ++cnt;
        ans += (ll) abs(a);
        mi = min(mi, abs(a));
    }
    if(cnt % 2) cout << ans - 2 * mi << endl;
    else cout << ans << endl;
    return 0;
}