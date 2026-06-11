#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
int main()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> lis(N);
    vector<pair<ll, ll>> a(M);
    rep(i, M)
    {
        cin >> a[i].first >> a[i].second;
        a[i].first--;
        lis[a[i].first].emplace_back(a[i].second);
    }
    rep(i, N)
    {
        sort(lis[i].begin(), lis[i].end());
    }
    rep(i, M)
    {
        ll v = a[i].first;
        ll id = lower_bound(lis[v].begin(), lis[v].end(), a[i].second) - lis[v].begin();
        printf("%06lld", v + 1);
        printf("%06lld\n", id + 1);
    }
}