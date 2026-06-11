#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

string s[110], t[110];

int main()
{
    int n, m;
    cin >> n;
    rep(i, n) cin >> s[i];
    cin >> m;
    rep(i, m) cin >> t[i];
    int ans = 0;
    rep(i, n) {
        int score = 0;
        rep(j, n) {
            if(s[j] == s[i]) score++;
        }
        rep(j, m) {
            if(t[j] == s[i]) score--;
        }
        ans = max(ans, score);
    }
    cout << ans << endl;
    return 0;
}
