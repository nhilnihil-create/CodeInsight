#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> sum(n+1);
    for(int i = 0; i < n; i++) sum[i+1] = sum[i] + a[i];
    unordered_map<ll, ll> mp;
    for(int i = 0; i <= n; i++){
        mp[sum[i]%m]++;
    }
    ll ans = 0;
    for(auto p : mp){
        ans += p.second * (p.second - 1) / 2;
    }
    cout << ans << endl;
}