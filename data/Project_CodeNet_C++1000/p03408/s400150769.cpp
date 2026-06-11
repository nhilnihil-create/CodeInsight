#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
using ll = long long;
using V = vector<int>;
using VV = vector<vector<int>>;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    rep(i, n)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    int m;
    cin >> m;
    rep(i, m)
    {
        string s;
        cin >> s;
        mp[s]--;
    }
    int ans = 0;
    for (auto p : mp)
    {
        ans = max(ans, p.second);
    }
    cout << ans << endl;
    return 0;
}