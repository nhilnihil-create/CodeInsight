#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'a' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int n, a, b, c;
int l[10];
int ans = INF;

int calc(string s) {
    int mp = 0;
    int cnt[3] = {};
    int suml[3] = {};
    rep(i, 0, s.size()) {
        int c = s[i] - '0';
        if (c == 3) continue;
        cnt[c]++;
        suml[c] += l[i];
    }
    rep(i, 0, 3) mp += (cnt[i] - 1) * 10;
    mp += abs(suml[0] - a) + abs(suml[1] - b) + abs(suml[2] - c);
    return mp;
}

bool is_ok(string s) {
    bool a, b, c;
    a = b = c = false;
    for (auto i : s) {
        if (i == '0') a = true;
        if (i == '1') b = true;
        if (i == '2') c = true;
    }
    return a && b && c;
}

void dfs(string s) {
    if ((int)s.size() == n) {
        if (is_ok(s)) {
            ans = min(ans, calc(s));
        }
        return;
    }
    rep(i, 0, 4) dfs(s + char(i + '0'));
}

int main() {
    cin >> n >> a >> b >> c;
    rep(i, 0, n) cin >> l[i];
    dfs("");
    cout << ans << endl;
    return 0;
}
