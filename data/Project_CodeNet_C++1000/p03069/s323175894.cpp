#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (ll)n; ++i)
#define repr(i, n) for (int i = n - 1; i >= 0; --i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve(void)
{
    int n;
    string s;
    cin >> n >> s;
    int cta = 0; //ctaは白の数
    rep(i, n) if (s[i] == '.') cta++;
    int ans = min(n - cta, cta);
    int b = 0, w = 0;
    rep(i, n - 1)
    {
        if (s[i] == '#')
            b++;
        else
            w++;
        if (s[i] != s[i + 1])
        {
            int x = b;
            int y = cta - w;
            ans = min(ans, x + y);
        }
    }
    cout << ans << endl;
}

int main(void)
{
    solve();
}
