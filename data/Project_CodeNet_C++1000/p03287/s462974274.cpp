#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n; ll m; cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n+1);
    map<int,ll> mp;
    sum[0] = 0;
    rep(i,n){
        sum[i+1] = (sum[i]+a[i])%m;
    }
    rep(i,n+1) mp[sum[i]]++;
    ll ans = 0;
    for(auto x : mp){
        ll y = x.second;
        ans += y*(y-1)/2;
    }
    cout << ans << endl;
}