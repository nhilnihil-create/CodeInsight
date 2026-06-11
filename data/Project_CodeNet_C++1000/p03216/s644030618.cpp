#include "bits/stdc++.h"
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < int(n); i++)
#define FOR(i,n,m) for(int i = int(n); i < int(m); i++)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = MOD - 1;
const ll LLINF = 4e18;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<ll> dm(n + 1, 0), d(n + 1, 0), m(n + 1, 0);
    REP(i, n) {
        d[i + 1] = d[i];
        m[i + 1] = m[i];
        dm[i + 1] = dm[i];
        if (s[i] == 'D') d[i + 1]++;
        if (s[i] == 'M') {
            m[i + 1]++;
            dm[i + 1] += d[i + 1];
        }
    }
    int q; cin >> q;
    REP(i, q) {
        int b; cin >> b;
        b--;
        ll ans = 0;
        REP(j, n) {
            if (s[j] == 'C') {
                ans += dm[j + 1] - dm[max(0, j - b)] - (d[max(0, j - b)])*(m[j + 1] - m[max(0, j - b)]);
            }
        }
        cout << ans << endl;
    }
}