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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> su(n, 0), cum(n + 1, 0);
    rep(i, n - 1)
    {
        if (s.substr(i, 2) == "AC")
        {
            su[i + 1]++;
        }
    }
    rep(i, n) cum[i + 1] += su[i] + cum[i];
    // rep(i, n + 1)
    // {
    //     cout << cum[i] << ' ';
    // }
    // cout << endl;

    rep(i, q)
    {
        int l, r;
        cin >> l >> r;

        cout << cum[r] - cum[l] << endl;
    }

    return 0;
}