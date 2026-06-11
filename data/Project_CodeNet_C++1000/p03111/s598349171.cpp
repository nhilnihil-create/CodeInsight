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

void dfs(string s, int a, int b, int c) {
    if ((int)s.size() == n) {
        if (a && b && c) ans = min(ans, calc(s));
        return;
    }
    dfs(s + '0', 1, b, c);
    dfs(s + '1', a, 1, c);
    dfs(s + '2', a, b, 1);
    dfs(s + '3', a, b, c);
}

int main() {
    cin >> n >> a >> b >> c;
    rep(i, 0, n) cin >> l[i];
    dfs("", 0, 0, 0);
    cout << ans << endl;
    return 0;
}
