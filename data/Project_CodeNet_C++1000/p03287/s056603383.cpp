#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n), s(n+1,0); rep(i,n) cin >> a[i];
    rep(i,n) s[i+1] = (s[i] + a[i])%m;
    ll ans = 0;


    map<ll,ll> mp;

    rep(i,n+1){
        ans += mp[s[i]];
        mp[s[i]]++;
    }

    cout << ans << endl;
}
