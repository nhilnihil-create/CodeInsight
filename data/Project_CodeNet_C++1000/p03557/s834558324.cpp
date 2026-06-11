#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = signed long long int;
using P = pair<int, int>;


int main (void) {
    int N;
    cin >> N;
    vector<vector<ll>> sizes(3, vector<ll>(N));
    
    rep(i, 3) rep(j, N) cin >> sizes.at(i).at(j);
    rep(i, 3) sort(sizes.at(i).begin(), sizes.at(i).end());
    
    ll ans = 0;
    rep(i, N) {
        ll x = lower_bound(sizes.at(0).begin(), sizes.at(0).end(), sizes.at(1).at(i)) - sizes.at(0).begin();
        ll y = sizes.at(2).end() - upper_bound(sizes.at(2).begin(), sizes.at(2).end(), sizes.at(1).at(i));
        if (x > N | y > N) continue;
        ans += x * y;
    }
    cout << ans << endl;
}
