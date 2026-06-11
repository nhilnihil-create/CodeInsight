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

#define GRAY 400
#define BROWN 800
#define GREEN 1200
#define SKY 1600
#define BLUE 2000
#define YELLOW 2400
#define ORANGE 2800
#define RED 3200
#define WHITE -1

void solve()
{
    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("./sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, int> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        mp[a]++;
    }

    int ans = 0;
    for (auto nmp : mp)
    {
        int key = nmp.first;
        int value = nmp.second;

        ans += (value - key >= 0) ? value - key : value;
    }

    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
