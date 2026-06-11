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
    std::ifstream in("./sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<char, int> mp;
    string march = "MARCH";
    rep(i, n)
    {
        string s;
        cin >> s;
        bool isMarch = false;
        rep(j, 5)
        {
            if (s[0] == march[j])
                isMarch = true;
        }
        if (isMarch)
            mp[s[0]]++;
    }

    int ans = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (i > j || j > k || i > k)
                    continue;
                if (i == j || j == k || k == i)
                    continue;

                ans += mp[march[i]] * mp[march[j]] * mp[march[k]];
            }
        }
    }

    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
