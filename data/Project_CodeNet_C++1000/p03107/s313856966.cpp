#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    string s;
    cin >> s;
    int n = s.size();
    int cnt0 = 0, cnt1 = 0;
    rep(i, 0, n) {
        if (s[i] == '0') {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    int ans = 2 * min(cnt0, cnt1);
    cout << ans << "\n";
}