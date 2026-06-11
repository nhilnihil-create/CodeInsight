#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    int as, k;
    vector<int> cnt(m, 0);

    rep(i, 0, n)
    {
        cin >> k;
        rep(j, 0, k)
        {
            cin >> as;
            cnt[as - 1]++;
        }
    }
    int ans = 0;

    rep(i, 0, m)
    {
        // cout << cnt[i] << endl;/
        if (cnt[i] == n)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
