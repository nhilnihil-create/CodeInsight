#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    string s, t = "ACGT";
    cin >> s;

    int res = 0, cnt = 0;
    rep(i, (int)s.size())
    {
        if (t.find(s[i]) != -1)
        {
            cnt++;
            res = max(res, cnt);
        }
        else
        {
            cnt = 0;
        }
    }
    cout << res << endl;
    return (0);
}
