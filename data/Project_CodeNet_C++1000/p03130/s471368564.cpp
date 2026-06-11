#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;

int s[5];

int main()
{
    rep(i, 3) {
        int a, b;
        cin >> a >> b;
        s[a]++;
        s[b]++;
    }
    string ans = "YES";
    repl(i, 1, 5) {
        if(s[i] == 3) ans = "NO";
    }
    cout << ans << endl;
    return 0;
}