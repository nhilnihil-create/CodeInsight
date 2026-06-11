#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> cnt(m, 0);
    rep (i, n)
    {
        int k;
        cin >> k;

        rep (i, k)
        {
            int a;
            cin >> a;
            cnt[a - 1]++;
        }
    }

    int ans = 0;
    for (auto v : cnt)
        if (v == n)
            ans++;

    cout << ans << endl;
    return 0;
}