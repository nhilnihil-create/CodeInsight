#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

int n;
string S, s, t;
typedef pair<string, string> PS;
map<PS, int> mp1, mp2;
set<PS> st;

void dfs(int p, string a, string b, bool f)
{
    if (p == n)
    {
        if (f)
        {
            mp1[PS(a, b)]++;
            st.insert(PS(a, b));
        }
        else
            mp2[PS(a, b)]++;
        return;
    }
    if (f)
    {
        dfs(p + 1, a + s[p], b, true);
        dfs(p + 1, a, b + s[p], true);
    }
    else
    {
        dfs(p + 1, a + t[p], b, false);
        dfs(p + 1, a, b + t[p], false);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> S;
    s = S.substr(0, n);
    t = S.substr(n, n);
    reverse(all(t));
    dfs(0, "", "", true);
    dfs(0, "", "", false);
    int ans = 0;
    for (auto x = st.begin(); x != st.end(); x++)
    {
        PS ps = *x;
        ans += mp1[ps] * mp2[ps];
    }
    cout << ans << endl;
}