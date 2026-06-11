#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define all(obj) (obj).begin(), (obj).end()
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
string s;

signed main()
{
    cin >> s;
    int l = 0, r = s.size() - 1;
    int cnt = 0;
    while (l < r) {
        if (s[l] == s[r]) {
            ++l;
            --r;
        } else if (s[l] == 'x') {
            ++l;
            ++cnt;
        } else if (s[r] == 'x') {
            --r;
            ++cnt;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    return 0;
}