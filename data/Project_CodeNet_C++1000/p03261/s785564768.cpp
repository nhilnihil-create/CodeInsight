#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<string> w(n);
    rep(i, n) cin >> w[i];
    string ans = "Yes";
    repl(i, 1, n) {
        if(w[i][0] != w[i - 1][w[i - 1].size() - 1]) ans = "No";
        rep(j, i) {
            if(w[i] == w[j]) ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}