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
    int n, m; cin >> n >> m;
    vi cnt(n + 2);
    FOR(i, 1, m) {
        int l, r; cin >> l >> r;
        cnt[l]++, cnt[r + 1]--;
    }
    int ans = 0;
    FOR(i, 1, n) {
        cnt[i] += cnt[i - 1];
        if (cnt[i] == m) ans++;
    }
    cout << ans << endl;
}