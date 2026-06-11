#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;
 
 
 
int main(){
   int n; cin >> n;
   vector<ll> a(n);
   rep(i,n) cin >> a[i];
 
    vector<ll> sum(n+1);
    rep(i,n){
        sum.at(i+1) = sum.at(i) + a.at(i);
    }
 
    map<ll,ll> nums;
    rep(i,n+1) nums[sum[i]] ++;
 
   
    ll ans=0;
    for(auto it:nums){
        ll num = it.second;
      ans += num*(num-1)/2;
    }
    cout << ans << endl;
}