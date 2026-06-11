#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

#define LEN 16010
#define SIZE 8000

bool in(int x)
{
    return 0 <= x && x < LEN;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    s.push_back('T');
    int x, y;
    cin >> x >> y;
    x += SIZE, y += SIZE;
    int cnt = 0;
    vector<int> vx, vy;
    bool f = true;
    rep(i, s.size())
    {
        if (s[i] == 'F')
            cnt++;
        else
        {
            if (f)
                vx.push_back(cnt), f = false;
            else
                vy.push_back(cnt), f = true;
            cnt = 0;
        }
    }
    bool dpx[LEN], dpy[LEN];
    rep(i, LEN) dpx[i] = dpy[i] = false;
    dpx[vx[0] + SIZE] = dpy[SIZE] = true;
    for (int i = 1; i < vx.size(); i++)
    {
        bool nxt[LEN];
        rep(j, LEN) nxt[j] = false;
        int len = vx[i];
        rep(j, LEN)
        {
            if (in(j - len))
                nxt[j] |= dpx[j - len];
            if (in(j + len))
                nxt[j] |= dpx[j + len];
        }
        rep(j, LEN) dpx[j] = nxt[j];
    }
    for (int i = 0; i < vy.size(); i++)
    {
        bool nxt[LEN];
        rep(j, LEN) nxt[j] = false;
        int len = vy[i];
        rep(j, LEN)
        {
            if (in(j - len))
                nxt[j] |= dpy[j - len];
            if (in(j + len))
                nxt[j] |= dpy[j + len];
        }
        rep(j, LEN) dpy[j] = nxt[j];
    }
    bool ans = dpx[x] && dpy[y];
    cout << (ans ? "Yes" : "No") << endl;
}