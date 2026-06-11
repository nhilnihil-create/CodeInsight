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
    ll k;
    cin >> s;
    cin >> k;
    int one = 0;
    rep(i, s.size()) {
        if(s[i] != '1') {
            one = i;
            break;
        }
    }
    one++;
    if(one <= k) cout << s[one - 1] << endl;
    else cout << 1 << endl;
    return 0;
}
