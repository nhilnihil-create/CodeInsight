#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
const int MOD = 1000000007;
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> st(m);
    rep(i, 0, n)
    {
        int x;
        cin >> x;
        rep(j, 0, x)
        {
            int y;
            cin >> y;
            st[--y].insert(i);
        }
    }
    int ans = 0;
    rep(i, 0, m) if (st[i].size() == n) ans++;
    cout << ans << endl;
}
