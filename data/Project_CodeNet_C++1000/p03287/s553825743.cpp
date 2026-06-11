#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    vector<ll> sum(n, 0);
    sum[0] = a[0];
    for(int i = 1; i < n; i++)sum[i] = sum[i-1] + a[i];
    ll ans = 0;
    rep(i, n){
        sum[i] %= m;
        if(sum[i] == 0)ans++;
    }

    map<ll, int> mp;
    rep(i, n)mp[sum[i]]++;
    for(auto i = mp.begin(); i != mp.end(); i++){
        ll k = i->second;
        ans += k * (k - 1) / 2;
    }
    cout << ans << endl;
}