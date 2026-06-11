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

int main() {
    int n; cin >> n;
    int x = 0, y = 0;
    vi t(n + 1);
    FOR(i, 1, n) {
        int tx, ty; cin >> t[i] >> tx >> ty;
        int d = abs(x - tx) + abs(y - ty), dt = t[i] - t[i - 1];
        // cout << d << ' ' << dt << endl;
        if (d > dt || abs(dt - d) % 2 == 1)
            return cout << "No\n", 0;
        x = tx, y = ty;
        
    }
    cout << "Yes\n";
}
