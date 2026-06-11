#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = -1;
    rep(i, n) {
        vector<int> a(26);
        vector<int> b(26);
        rep(j, i + 1) {
            a[s[j] - 'a']++;
        }
        repl(j, i + 1, n) {
            b[s[j] - 'a']++;
        }
        int t = 0;
        rep(j, 26) {
            if(a[j] != 0 && b[j] != 0) t++;
        }
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
