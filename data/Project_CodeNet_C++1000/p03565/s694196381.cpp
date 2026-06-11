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

ll mod = 1000000007;

signed main()
{
    string s, t;
    cin >> s >> t;
    set<string> ss;
    rep(i, s.size() - t.size() + 1)
    {
        bool f = true;
        rep(j, t.size())
        {
            if (s[i + j] != t[j] && s[i + j] != '?')
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            string str = s;
            rep(j, s.size())
            {
                if (s[j] == '?')
                {
                    str[j] = 'a';
                }
            }
            rep(j, t.size())
            {
                str[i + j] = t[j];
            }
            ss.insert(str);
        }
    }
    if (ss.size() == 0)
    {
        cout << "UNRESTORABLE" << endl;
    }
    else
    {
        cout << *(ss.begin()) << endl;
    }
}