#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
    string s, t;
    cin >> s >> t;
    ll n = s.length();
    ll m = t.length();
    vector<string> ans;

    if (n < m)
    {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for (ll i = 0; i <= n - m; i++)
    {
        bool ok = true;
        string tmp = s;
        for (ll j = 0; j < m; j++)
        {
            if (s[i + j] != '?' && s[i + j] != t[j])
                ok = false;
            tmp[i + j] = t[j];
        }
        if (ok)
            ans.push_back(tmp);
    }

    if (ans.size() == 0)
    {
        cout << "UNRESTORABLE" << endl;
    }
    else
    {
        sort(ans.begin(), ans.end());
        rep(i, n)
        {
            if (ans[0][i] == '?')
                ans[0][i] = 'a';
        }
        cout << ans[0] << endl;
    }
}