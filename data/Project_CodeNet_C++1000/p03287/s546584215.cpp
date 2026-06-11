#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin>>N>>M;
    unordered_map<ll, ll> mp;
    ll s = 0;
    rep(i, N) {
        ll a;
        cin>>a;
        s = (s + a) % M;
        mp[s] += 1;
    }
    ll ans = 0;
    for (auto c : mp) {
        if (c.first == 0) ans += c.second * (c.second + 1) / 2;
        else ans += c.second * (c.second - 1) / 2;
    }
    cout<<ans<<endl;
}