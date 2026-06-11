#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> s(n+1, 0);
    map<ll, ll> mp;
    ll ans = 0;
    mp[0]++;
    rep(i, 1, n+1){
        ll a; cin >> a;
        s[i] = s[i-1] + a;
        ans += mp[s[i] % m];
        mp[s[i] % m]++;
    }
    cout << ans << endl;
    return 0;
}