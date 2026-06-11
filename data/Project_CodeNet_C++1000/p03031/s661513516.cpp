#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    vector<int> p(m);
    rep(i, m)
    {
        int k;
        cin >> k;
        s[i].resize(k);
        rep(j, k) cin >> s[i][j];
    }
    rep(i, m) cin >> p[i];

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++)
    {
        int light = 0;
        rep(i, m)
        {
            int cnt = 0;
            rep(j, s[i].size())
            {
                if (bit & (1 << s[i][j] - 1))
                {
                    cnt++;
                }
            }
            if (cnt % 2 == p[i])
            {
                light++;
            }
        }
        if (light == m)
        {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
