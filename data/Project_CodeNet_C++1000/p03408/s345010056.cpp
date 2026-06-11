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
    int n, m;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    cin >> m;
    vector<string> t(m);
    rep(i, m) cin >> t[i];

    int ans = 0;
    rep(i, n)
    {
        int tmp = 0;
        rep(k, n) if (s[i] == s[k]) tmp++;
        rep(j, m) if (s[i] == t[j]) tmp--;

        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return (0);
}
