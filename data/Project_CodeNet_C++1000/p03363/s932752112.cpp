#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;

int main()
{
    int n;
    cin >> n;
    vector<ll> sum(n+1);
    sum[0] = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        sum[i + 1] = sum[i] + a;
    }
    map<ll,ll> mp;
    rep(i, n + 1) {
        mp[sum[i]]++;
    }
    ll ans = 0;
    for(auto x : mp) {
        ans += x.second * (x.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}