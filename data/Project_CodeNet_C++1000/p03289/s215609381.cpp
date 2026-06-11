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
    string ans = "AC";
    if(s[0] != 'A') ans = "WA";
    int cnt = 0;
    repl(i, 1, s.size()) {
        if(isupper(s[i])) {
            if(i == 1 || s[i] != 'C' || i == s.size() - 1) ans = "WA";
            cnt++;
        }
    }
    if(cnt != 1) ans = "WA";
    cout << ans << endl;
    return 0;
}