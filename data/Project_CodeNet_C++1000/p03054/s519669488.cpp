#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define Repr(i, n, a) for (int i = (n); i >= (a); i--)
#define rep(i, n) Rep(i, 0, n)
#define repr(i, n) Repr(i, n, 0)
#define all(a) a.begin(), a.end()
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;

int n, h, w, y, x;
string s, t;

bool solve(int len, int pos, vector<int> v, vector<bool> f)
{
    int L = 1, R = len;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (f[i])
        {
            if (v[i] == 1)
                R--;
            else
                L++;
        }
        else
        {
            if (v[i] == 1)
                L = max(L - 1, 1LL);
            else
                R = min(R + 1, len);
        }
        if (L > R)
            return false;
    }
    return (L <= pos && pos <= R);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> h >> w >> n >> y >> x >> s >> t;
    vector<int> v_h, v_w;
    vector<bool> f_h, f_w;
    rep(i, n)
    {
        if (s[i] == 'U')
        {
            v_h.push_back(-1);
            f_h.push_back(true);
        }
        if (s[i] == 'D')
        {
            v_h.push_back(1);
            f_h.push_back(true);
        }
        if (s[i] == 'L')
        {
            v_w.push_back(-1);
            f_w.push_back(true);
        }
        if (s[i] == 'R')
        {
            v_w.push_back(1);
            f_w.push_back(true);
        }
        if (t[i] == 'U')
        {
            v_h.push_back(-1);
            f_h.push_back(false);
        }
        if (t[i] == 'D')
        {
            v_h.push_back(1);
            f_h.push_back(false);
        }
        if (t[i] == 'L')
        {
            v_w.push_back(-1);
            f_w.push_back(false);
        }
        if (t[i] == 'R')
        {
            v_w.push_back(1);
            f_w.push_back(false);
        }
    }
    bool f = solve(h, y, v_h, f_h) && solve(w, x, v_w, f_w);
    cout << (f ? "YES" : "NO") << endl;
}