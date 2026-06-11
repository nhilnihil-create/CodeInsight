#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const ll INF = 1001001001;

int main()
{
    int n;
    cin >> n;
    string ans = "Yes";
    int xx = 0;
    int yy = 0;
    int tt = 0;
    rep(i, n) {
        int t, x, y;
        cin >> t >> x >> y;
        int dist = abs(x - xx) + abs(y - yy);
        tt = t - tt;
        if(tt < dist) ans = "No";
        else {
            if(tt % 2 != dist % 2) {
                ans = "No";
            }
        }
        tt = t;
        xx = x;
        yy = y;
    }
    cout << ans << endl;
    return 0;
}
