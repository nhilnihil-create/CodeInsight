#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
ll mod = 1e9+7;


int main(){
    int n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    rep(i,n) mp[a[i]] += b[i];
    sort(a.begin(), a.end());
    int i = 0;
    ll sum=0, ans = 0;
    for(i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]) continue;
        if(sum + mp[a[i]] >= m){
            ans += (m-sum)*a[i]; 
            break;
        }
        sum += mp[a[i]];
        ans += a[i] * mp[a[i]];
    }
    cout << ans << endl;
}