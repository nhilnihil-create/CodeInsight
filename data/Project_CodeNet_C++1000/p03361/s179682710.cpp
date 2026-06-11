#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define ROF(i, a, b) for (int i = a; i >= (b); i--)

using pii = pair<int, int>; using vpii = vector<pii>;
using vi = vector<int>; using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>; using vpll = vector<pll>;
using vll = vector<ll>; using vvll = vector<vll>;

pii ch[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
    int h, w; cin >> h >> w;
    vector <vector <char> > c(h + 1, vector <char> (w + 1));
    FOR(i, 1, h) FOR(j, 1, w)
        cin >> c[i][j];
    bool ok = 1;
    FOR(i, 1, h) FOR(j, 1, w) if (c[i][j] == '#') {
        bool hv = 0;
        FOR(k, 0, 3) {
            int tx = i + ch[k].fi, ty = j + ch[k].se;
            if (tx > h || tx < 1 || ty > w || ty < 1) continue;
            if (c[tx][ty] == '#') hv = 1;
        }
        if (!hv) ok = 0;
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}