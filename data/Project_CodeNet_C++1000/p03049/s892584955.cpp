#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int dxx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 }, dyy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {
    int n;
    cin >> n;
    int cnta = 0, cntb = 0, cntab = 0, ans = 0;
    string s[n];
    rep (i, n) {
        cin >> s[i];
        rep (j, s[i].size() - 1) {
            if (s[i][j] == 'A' && s[i][j + 1] == 'B') ans++;
        }
        if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') cntab++;
        else if (s[i][0] == 'B')
            cntb++;
        else if (s[i][s[i].size() - 1] == 'A')
            cnta++;
    }
    if (cntab == 0) {
        ans += min (cnta, cntb);
    } else {
        if (cnta == 0 && cntb == 0) ans += cntab - 1;
        else
            ans += min (cnta, cntb) + cntab;
    }
    cout << ans << "\n";
}
