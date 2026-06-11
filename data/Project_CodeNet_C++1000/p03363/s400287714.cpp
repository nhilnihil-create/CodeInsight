#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    rep(i, n-1)a[i+1] += a[i];
    map<ll, int> mp;
    rep(i, n)mp[a[i]]++;
    ll ans = 0;
    for(auto p : mp){
        if(p.first == 0){
            ans += p.second;
        }
        ll k = p.second;
        ans += k * (k - 1) / 2;
    }
    cout << ans << endl;
}