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

    int n;
    cin >> n;
    int BA, XX, XA, BX, cnt;
    BA = XX = XA = BX = cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s[0] == 'B' && s[s.size() - 1] == 'A')
            BA++;
        else if (s[0] != 'B' && s[s.size() - 1] != 'A')
            XX++;
        else if (s[0] == 'B')
            BX++;
        else
            XA++;

        for (int j = 0; j < s.size() - 1; j++)
        {
            if (s[j] == 'A' && s[j + 1] == 'B')
                cnt++;
        }
    }

    if (1 <= BA)
    {
        cnt += BA - 1;
        if (BX > 0 && XA > 0)
        {
            cnt += 2;
            cnt += min(BX, XA) - 1;
        }
        else if (BX == 0 && XA == 0)
        {
            //do nothing
        }
        else
        {
            cnt++;
        }
    }
    else
    {
        cnt += min(BX, XA);
    }

    cout << cnt << endl;
}

signed main()
{
    solve();
    return 0;
}
