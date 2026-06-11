#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

void chmax(string &a, const string &b) {
    if (a.length() > b.length()) {
        return;
    }
    if (a.length() < b.length()) {
        a = b;
        return;
    }
    if (a < b) {
        a = b;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    //              0  1  2  3  4  5  6  7  8  9
    int match[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    string inf = "#";
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    vector<string> dp(n + 1, inf);
    dp[0] = "";
    rep(i, n) {
        if (dp[i] == inf) continue;
        for (auto x : a) {
            int idx = i + match[x];
            if (idx > n) continue;
            chmax(dp[idx], dp[i] + (char)('0' + x));
        }
    }
    cout << dp[n] << endl;
    return 0;
}
