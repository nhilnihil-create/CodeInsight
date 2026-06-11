#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), s(n+1, 0);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) s[i+1] = s[i] + a[i]; 
    map<ll,ll> mp;
    ll ans = 0;
    rep(i, 0, n+1) {
        ans += mp[s[i]];
        mp[s[i]]++;
    }
    cout << ans << endl;
    return 0;
}