#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<pair<pair<string, int>, int>> g(n);
    rep(i, n)
    {
        string s;
        int p;
        cin >> s >> p;
        g[i] = make_pair(make_pair(s, -p), i + 1);
    }
    sort(g.begin(), g.end());
    rep(i, n)
    {
        // cout << g[i].first.first << " " << g[i].first.second << " " << endl;
        cout << g[i].second << endl;
    }
    return 0;
}