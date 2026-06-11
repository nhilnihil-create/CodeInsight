#include <bits/stdc++.h>
#define reps(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define rep(i, n) reps(i, 0, n - 1)
#define sper(i, s, n) for (int i = (s); i >= (int)(n); i--)
#define per(i, n) sper(i, n - 1, 0)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int d, g, p[11], c[11];
int ans = 1e9;

void dfs(string s)
{
    if (s.size() == d)
    {
        int score = 0, cnt = 0;
        rep(i, d)
        {
            if (s[i] == '1')
            {
                score += p[i] * 100 * (i + 1) + c[i];
                cnt += p[i];
            }
            if (score >= g)
            {
                ans = min(ans, cnt);
                break;
            }
        }
        per(j, d)
        {
            if (s[j] == '1' || score >= g)
                continue;
            rep(k, p[j])
            {
                score += (j + 1) * 100;
                cnt++;
                if (score >= g)
                {
                    ans = min(ans, cnt);
                    break;
                }
            }
        }
        return;
    }
    dfs(s + "0");
    dfs(s + "1");
}

void solve()
{
    cin >> d >> g;
    rep(i, d) cin >> p[i] >> c[i];
    dfs("");
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}