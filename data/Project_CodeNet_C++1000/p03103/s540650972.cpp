#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;

int main() {
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> a(n); REP(i, n) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());

    ll sum = 0; ll num = 0; ll cur = 0;
    while(num < m) {
        ll tmp = min(a[cur].second, m - num);
        sum += a[cur].first * tmp;
        num += tmp;
        ++cur;
    }

    cout << sum << endl;

    return 0;
}