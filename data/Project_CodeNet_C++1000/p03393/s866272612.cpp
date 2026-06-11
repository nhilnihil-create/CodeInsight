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
    string s;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    cin >> s;
    if (s == "zyxwvutsrqponmlkjihgfedcba")
    {
        cout << -1 << endl;
    }
    else
    {
        if (s.size() == 26)
        {
            string ss = s;
            next_permutation(all(s));
            rep(i, s.size())
            {
                if (s[i] == ss[i])
                {
                    cout << s.substr(i, 1);
                }
                else
                {
                    cout << s.substr(i, 1) << endl;
                    return 0;
                }
            }
        }
        else
        {
            vi a(26);
            rep(i, s.size())
            {
                a[s[i] - 'a']++;
            }
            cout << s;
            rep(i, a.size())
            {
                if (a[i] == 0)
                {
                    cout << alphabet.substr(i, 1) << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}