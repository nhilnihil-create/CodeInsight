#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rev(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define all(v) v.begin(), v.end()
#define println(x) cout << x << endl
#define fi first
#define se second
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
using pii = pair<int, int>;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> s(m, vector<int>());
    rep(i, m)
    {
        cin >> k[i];
        rep(j, k[i])
        {
            int sij; cin >> sij;
            s[i].push_back(sij - 1);
        }
    }
    vector<int> p(m);
    rep(i, m)
    {
        cin >> p[i];
    }
    int ans = 0;
    bitrep(t, n)
    {
        bitset<10> bs(t);
        int cnt = 0;
        rep(i, m)
        {
            int cnt_i = 0;
            rep(j, k[i])
            {
                if (bs[s[i][j]] == 1) cnt_i++;
            }
            if (cnt_i % 2 == p[i]) cnt++;
        }
        if (cnt == m) ans++;
    }
    cout << ans << endl;
}