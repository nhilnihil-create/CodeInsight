#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> x(n);
    rep(i, n)cin >> x[i].first >> x[i].second;
    sort(x.begin(), x.end());

    ll ans = 4001001001001001001;
    rep(i, n-1)for(int j = i+1; j < n; j++){
        if(j-i+1 < k)continue;
        vector<ll> yy;
        for(int l = i; l <= j; l++)yy.push_back(x[l].second);
        sort(yy.begin(), yy.end());
        ll dy = 2002002002;
        rep(l, yy.size()-k+1)dy = min(dy, yy[l+k-1]-yy[l]);
        ans = min(ans, dy * (x[j].first-x[i].first));
    }
    cout << ans << endl;
}