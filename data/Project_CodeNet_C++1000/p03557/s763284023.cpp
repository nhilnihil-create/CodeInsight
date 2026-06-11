#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = signed long long int;
using P = pair<int, int>;
int main (void) {
    int N;
    cin >> N;
    vector<vector<ll>> abc(3, vector<ll>(N));
    rep(i, 3) rep(j, N) cin >> abc.at(i).at(j);
    rep(i, 3) sort(abc.at(i).begin(), abc.at(i).end());
    
    ll ans = 0;
    rep(i, N)  {
        ll key = abc.at(1).at(i);
        ll x = upper_bound(abc.at(0).begin(), abc.at(0).end(), key-1) - abc.at(0).begin();
        ll y = abc.at(2).end() - upper_bound(abc.at(2).begin(), abc.at(2).end(), key);
        ans += x * y;

    }
    cout << ans << endl;
}
