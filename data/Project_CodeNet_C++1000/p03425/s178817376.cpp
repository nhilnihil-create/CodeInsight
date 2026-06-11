#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

char x[5] = {'M', 'A', 'R', 'C', 'H'};

int main()
{
    int n;
    cin >> n;
    map<char, int> mp;
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, 5) {
            if(s[0] == x[j]) mp[x[j]]++;
        }
    }
    ll ans = 0;
    ans += (ll) mp[x[0]] * mp[x[1]] * mp[x[2]] + (ll) mp[x[0]] * mp[x[1]] * mp[x[3]] + (ll) mp[x[0]] * mp[x[1]] * mp[x[4]] + (ll) mp[x[0]] * mp[x[2]] * mp[x[3]] + (ll) mp[x[0]] * mp[x[2]] * mp[x[4]] + (ll) mp[x[0]] * mp[x[3]] * mp[x[4]] + (ll) mp[x[1]] * mp[x[2]] * mp[x[3]] + (ll) mp[x[1]] * mp[x[2]] * mp[x[4]] + (ll) mp[x[1]] * mp[x[3]] * mp[x[4]] + (ll) mp[x[2]] * mp[x[3]] * mp[x[4]];
    cout << ans << endl;
    return 0;
}
