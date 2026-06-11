#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int f(int n)
{
    return ((n % 2 == 0) ? n / 2 : 3 * n + 1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    rep(i, n)
    {
        int k;
        cin >> k;
        a[i].resize(k);
        rep(j, k) cin >> a[i][j];
    }

    map<int, int> mp;
    rep(i, n)
    {
        rep(j, a[i].size())
        {
            mp[a[i][j]]++;
        }
    }

    int ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        if (itr->second == n)
        {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
