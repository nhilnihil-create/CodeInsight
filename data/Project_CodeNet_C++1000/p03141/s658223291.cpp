#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];
    vector<pair<int,int>> diff(n);
    REP(i, n) diff[i] = make_pair(a[i] + b[i], i);
    sort(diff.begin(), diff.end(), greater<pair<int,int>>());
    ll ans = 0;
    for(int i = 0; i < n; i += 2) {
        ans += a[diff[i].second];
    }
    for(int i = 1; i < n; i += 2) {
        ans -= b[diff[i].second];
    }
    cout << ans << endl;

    return 0;
}