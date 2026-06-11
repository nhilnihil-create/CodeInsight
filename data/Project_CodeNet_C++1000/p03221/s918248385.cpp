#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1

using namespace std;
const int INF = 1e18;

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int p[m], y[m];
    rep(im, m)
    {
        cin >> p[im] >> y[im];
    }

    vector<pair<pair<int, int>, int>> yp;
    rep(i, m)
    {
        yp.push_back(make_pair(make_pair(y[i], p[i]), i));
    }
    sort(ALL(yp));
    map<int, int> mp;
    vector<pair<int, string>> ans;
    rep(i, m)
    {
        auto now = yp[i].first;
        auto num = yp[i].second;
        int ny = now.first;
        int np = now.second;
        mp[np]++;
        //string nyStr = to_string(ny);
        string nnStr = to_string(mp[np]);
        string npStr = to_string(np);
        while (nnStr.size() < 6)
        {
            nnStr = '0' + nnStr;
        }
        while (npStr.size() < 6)
        {
            npStr = '0' + npStr;
        }

        ans.push_back(make_pair(num, npStr + nnStr));
    }
    sort(ALL(ans));
    rep(i, m)
    {
        cout << ans[i].second << endl;
    }
}

signed main()
{
    solve();
    return 0;
}
