#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    vector<int> cnt(41);
    rep(i, n){
        rep(j, 41){
            if(1 & (a[i] >> j))cnt[j]++;
        }
    }
    vector<bool> one(41);
    rep(i, 41)if(cnt[i] <= n / 2)one[i] = true;

    ll x = 0;
    ll p = pow((ll)2, 40);
    for(int i = 40; i >= 0; i--){
        if(one[i] && x + p <= k)x += p;
        p /= 2;
    }
    ll ans = 0;
    rep(i, n)ans += x ^ a[i];
    cout << ans << endl;
}