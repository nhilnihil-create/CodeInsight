#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

vector<ll> yakusu(ll n) {
    vector<ll> res;
    for (ll i = 1; i*i <= n; i++) {
        if (n%i == 0) {
            res.push_back(i);
            if (n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    ll m;
    cin >> n >> m;
    auto f = yakusu(m);
    auto iter = lower_bound(f.begin(), f.end(), n);
    ll ans = *iter;
    ans = m/ans;
    cout << ans << endl;
    return 0;
}