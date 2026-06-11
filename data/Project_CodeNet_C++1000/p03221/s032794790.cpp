#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> a(m);
    rep (i, m)
    {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    vector<pair<int, pair<int, int>>> ans(m);
    vector<int> cnt(n + 1, 1);
    rep (i, m)
    {
        ans[i].first = a[i].second;
        ans[i].second.first = a[i].first.first;
        ans[i].second.second = cnt[a[i].first.first]++;
    }

    sort(ans.begin(), ans.end());
    rep (i, m)
        printf("%06d%06d\n", ans[i].second.first, ans[i].second.second);
    return 0;
}