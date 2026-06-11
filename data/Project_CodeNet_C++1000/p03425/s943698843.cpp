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
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    map<char, ll> mp;
    rep(i, n) mp[s[i][0]]++;

    vector<int> v(5);
    rep(i, 5) v[i] = i;
    string march = "MARCH";

    ll ans = 0;
    rep(i, 5)
    {
        rep2(j, i + 1, 5)
        {
            rep2(k, j + 1, 5)
            {
                ans += mp[march[i]] * mp[march[j]] * mp[march[k]];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
