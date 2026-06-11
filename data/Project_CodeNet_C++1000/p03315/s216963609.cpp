#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;
void solve(void)
{
    string s;
    cin >> s;
    map<char, int> mp;
    rep(i, s.length()) mp[s[i]]++;
    cout << mp['+'] - mp['-'] << endl;
}
int main(void)
{
    solve();
}