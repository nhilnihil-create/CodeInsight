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
    int a, b;
    string s;
    cin >> a >> b >> s;
    string ans = "Yes";
    if (s[a] != '-')
        ans = "No";
    rep(i, a)
    {
        if ('0' <= s[i] && s[i] <= '9')
            continue;
        else
            ans = "No";
    }
    for (int i = b + 1; i <= a + b; ++i)
    {
        if ('0' <= s[i] && s[i] <= '9')
            continue;
        else
            ans = "No";
    }
    cout << ans << endl;
}
int main(void)
{
    solve();
}