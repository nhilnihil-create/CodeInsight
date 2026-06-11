#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k,a;
  cin >> n >> k;
  vector<ll> cnt(k+1);
  cnt[0] = 1;
  for(int i = 0; i < n; ++i){
    cin >> a;
    ll tmp = 0;
    for(int j = k; j >= k-a; --j) tmp = (tmp+cnt[j])%mod;
    for(int j = k; j > 0; --j){
      tmp = (tmp-cnt[j])%mod;
      cnt[j] = (cnt[j]+tmp)%mod;
      if(j-a > 0) tmp = (tmp+cnt[j-a-1])%mod;
    }
  }
  cout << (cnt[k]+mod)%mod;
  return 0;
}