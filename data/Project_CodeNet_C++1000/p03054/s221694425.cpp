#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    int sx, sy;
    cin >> sx >> sy;
    --sx, --sy;
    string s, t;
    cin >> s >> t;
    bool win = false;
    int cx = sx;
    for (int i = 0; i < k; ++i) {
    	if (s[i] == 'U') --cx;
    	if (cx < 0) win = true;
    	if (t[i] == 'D' && cx + 1 < n) ++cx;
    }
    cx = sx;
    for (int i = 0; i < k; ++i) {
    	if (s[i] == 'D') ++cx;
    	if (cx >= n) win = true;
    	if (t[i] == 'U' && cx > 0) --cx;
    }
    int cy = sy;
    for (int i = 0; i < k; ++i) {
    	if (s[i] == 'L') --cy;
    	if (cy < 0) win = true;
    	if (t[i] == 'R' && cy + 1 < m) ++cy;
    }
    cy = sy;
    for (int i = 0; i < k; ++i) {
    	if (s[i] == 'R') ++cy;
    	if (cy >= m) win = true;
    	if (t[i] == 'L' && cy > 0) --cy;
    }
    cout << (win ? "NO" : "YES") << '\n';
}