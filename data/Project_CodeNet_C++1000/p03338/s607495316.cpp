#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
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
    int ans = 0;
    rep(i, n)
    {
        string x = s.substr(0, i);
        string y = s.substr(i, n - i);
        set<char> sx, sy;
        rep(j, i) sx.insert(x[j]);
        rep(j, n - i) sy.insert(y[j]);
        int res = 0;
        for (auto i : sx)
        {
            if (sy.find(i) != sy.end())
                res++;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}