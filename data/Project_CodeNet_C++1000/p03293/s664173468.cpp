#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    string ans = "No";
    rep(i, s.size()) {
        if(s == t) {
            ans = "Yes";
            break;
        }
        string u = s.substr(s.size() - 1);
        s.insert(0, u);
        s.pop_back();
    }
    cout << ans << endl;
    return 0;
}