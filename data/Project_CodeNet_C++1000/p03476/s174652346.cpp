#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

const int INF = 1001001001;

int ck(int a)
{
    if (a == 1)
    {
        return 0;
    }
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int q;
    cin >> q;

    vector<int> l(q), r(q);
    rep(i, q) cin >> l[i] >> r[i];
    int r_max = -INF;
    rep(i, q) r_max = max(r_max, r[i]);

    vector<int> tmp(100000 + 10, 0), s(100000 + 10, 0);
    rep(num, r_max + 1)
    {
        if (num % 2 == 0)
            continue;
        if (ck(num) && ck((num + 1) / 2))
        {
            tmp[num]++;
        }
    }
    // rep(i, tmp.size())
    // {
    //     if (0 <= i && i <= r_max)
    //     {
    //         cout << tmp[i] << ' ';
    //     }
    // }
    // cout << endl;

    rep(i, s.size())
    {
        s[i + 1] = s[i] + tmp[i];
    }

    // rep(i, s.size())
    // {
    //     if (0 <= i && i <= r_max)
    //     {
    //         cout << s[i] << ' ';
    //     }
    // }
    // cout << endl;

    rep(i, q)
    {
        cout << s[r[i] + 1] - s[l[i]] << endl;
    }

    return 0;
}