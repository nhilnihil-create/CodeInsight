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

//ll mod = 1000000007;
ll mod = 998244353;

signed main()
{
    int n;
    cin >> n;
    int in_ab = 0;
    int first_b = 0;
    int last_a = 0;
    int first_b_and_last_a = 0;
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, s.size() - 1)
        {
            if (s[j] == 'A' && s[j + 1] == 'B')
            {
                in_ab++;
            }
        }
        if (s[0] == 'B' && s[s.size() - 1] == 'A')
        {
            first_b_and_last_a++;
        }
        else
        {
            if (s[0] == 'B')
            {
                first_b++;
            }
            if (s[s.size() - 1] == 'A')
            {
                last_a++;
            }
        }
    }
    int ans = 0;
    if (first_b_and_last_a == 0)
    {
        ans = min(first_b, last_a) + in_ab;
    }
    else if (first_b == 0 && last_a == 0)
    {
        ans = in_ab + first_b_and_last_a - 1;
    }
    else
    {
        ans = first_b_and_last_a + min(first_b, last_a) + in_ab;
    }
    cout << ans << endl;
    return 0;
}