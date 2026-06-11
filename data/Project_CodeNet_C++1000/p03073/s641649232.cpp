#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    string s;
    cin >> s;
    int ans = 0;
    repl(i, 1, s.size()) {
        if(s[i] == s[i - 1]) {
            ans++;
            if(s[i - 1] == '0') s[i] = '1';
            else s[i] = '0';
        }
    }
    cout << ans << endl;
    return 0;
}