#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> abc(3, vector<ll>(N));
    rep(i, 3) rep(j, N) cin >> abc.at(i).at(j);

    rep(i, 3) sort(abc.at(i).begin(), abc.at(i).end());
    
    ll ans = 0;
    rep(j, N) {
        ll i = lower_bound(abc.at(0).begin(), abc.at(0).end(), abc.at(1).at(j)) - abc.at(0).begin();
        ll k = upper_bound(abc.at(2).begin(), abc.at(2).end(), abc.at(1).at(j)) - abc.at(2).begin();
        ans += i * (N - k);
    }
    
    cout << ans << endl;
}
