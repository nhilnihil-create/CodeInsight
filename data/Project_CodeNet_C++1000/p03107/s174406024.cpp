#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int r = 0;
    int b = 0;
    rep(i, s.size()) {
        if(s[i] == '0') r++;
        else b++;
    }
    cout << 2 * min(r, b) << endl;
    return 0;
}
