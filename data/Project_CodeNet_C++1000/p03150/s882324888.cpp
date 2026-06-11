#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    bool ans = false;
    rep(i, n + 1) {
        repl(j, i, n + 1) {
            string t = s.substr(0, i) + s.substr(j);
            if(t == "keyence") ans = true;
        }
    }
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
