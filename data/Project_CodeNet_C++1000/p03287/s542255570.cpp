#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
int main() {
    ll n, m; cin >> n >> m;
    map<ll,ll> mp;
    vector<ll> s(n);
    cin >> s[0]; s[0]%=m;
    mp[s[0]]++;
    rep(i, n-1) {
        int a;
        cin >> a;
        s[i+1] = (s[i]+a)%m;
        mp[s[i+1]]++;
    }
    //rep(i, n) cout << s[i];
    ll ans = 0LL;
    for(auto i = mp.begin(); i != mp.end() ; ++i) {
        ll f = i->first; ll s = i->second;
        if(f == 0) ans += s;
        ans += (s-1)*s/2LL;
    }
    cout << ans;
}

