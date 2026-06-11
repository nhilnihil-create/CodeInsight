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

    string s;
    cin >> s;
    int k;
    cin >> k;

    int notone = INF;
    rep(i, s.size())
    {
        if (s[i] != '1')
        {
            notone = i;
            break;
        }
    }

    if (notone == INF)
    {
        cout << 1 << endl;
    }
    else
    {
        if (k - 1 < notone)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << s[notone] << endl;
        }
    }
}

signed main()
{
    solve();
    return 0;
}
