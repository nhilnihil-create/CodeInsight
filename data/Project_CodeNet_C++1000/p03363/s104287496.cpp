#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const ll MOD = 1e9+7;
const int INF = 1001001001;
// const ll INF = 1000000000000000000LL;
  
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> table(n+1);
    for(int i=1;i<=n;i++){
        table[i] = table[i-1]+a[i-1];
    }
    map<ll,ll> mp;
    rep(i,n+1)
        mp[table[i]]++;
    ll ans = 0;
    for(auto iter:mp){
        if(iter.second>1){
            ll cur = iter.second*
            (iter.second-1);
            cur/=2;
            ans+=cur;
        }
    }
    cout << ans << endl;
    return 0;
}