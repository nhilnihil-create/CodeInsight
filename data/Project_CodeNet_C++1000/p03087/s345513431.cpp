#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int str_len = s.size();
    vector<int> ck_ac(str_len, 0);
    rep(i, str_len - 1)
    {
        if (s.substr(i, 2) == "AC")
        {
            ck_ac[i + 1]++;
        }
    }

    vector<int> cum(str_len + 1, 0);
    rep(i, str_len) cum[i + 1] = cum[i] + ck_ac[i];

    rep(i, q)
    {
        int l, r;
        cin >> l >> r;

        cout << cum[r] - cum[l] << endl;
    }

    return 0;
}