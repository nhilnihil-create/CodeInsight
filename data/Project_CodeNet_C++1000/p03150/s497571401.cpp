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
string keyence = "keyence";
int main()
{
    string s;
    cin >> s;
    int l = s.size();
    if (s == keyence)
    {
        cout << "YES" << endl;
        return 0;
    }
    for (size_t i = 0; i < l; i++)
    {
        for (size_t j = i; j < l; j++)
        {
            string a = "";
            for (size_t k = 0; k < l; k++)
            {
                if (i <= k && k <= j)
                {
                    continue;
                }
                else
                {
                    a.push_back(s[k]);
                }
            }
            if (a == keyence)
            {
                cout << "YES" << endl;
                return 0;
            }

            /* code */
        }
    }
    cout << "NO" << endl;

    return 0;
}