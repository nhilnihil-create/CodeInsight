#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> vs;
    rep(i, h)
    {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    rep(i, h)
    {
        rep(j, w)
        {
            int adj[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            bool f = false;
            if (vs[i][j] == '.')
            {
                continue;
            }
            for (size_t k = 0; k < 4; k++)
            {
                int x = i + adj[k][0];
                int y = j + adj[k][1];
                if (x < 0 || x >= h || y < 0 || y >= w)
                {
                    continue;
                }
                else if (vs[x][y] == '#')
                {
                    f = true;
                    break;
                }
            }
            if (!f)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}