#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
double pi = 3.14159265359;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    string s, t;
    cin >> s;
    rep (i, 0, s.size()) {
        if (s[i] == 'x') continue;
        t += s[i];
    }
    rep (i, 0, t.size()) {
        if (t[i] != t[t.size() - 1 - i]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    int nl = 0, nr = s.size() - 1;
    int ans = 0;
    while (nl < nr) {
        int cntl = 0, cntr = 0;
        while (s[nl] == 'x') {
            nl++;
            cntl++;
        }
        while (s[nr] == 'x') {
            nr--;
            cntr++;
        }
        // cout << nl << " " << nr << "\n";
        // cout << cntl << " " << cntr << "\n";
        nl++, nr--;
        ans += abs (cntr - cntl);
    }
    cout << ans << "\n";
}