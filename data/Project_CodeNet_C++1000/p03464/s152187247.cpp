#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int k;
  cin >> k;
  vector<ll> a(k);
  rep(i,k)cin >> a[i];
  ll pre = a.back();
  for(int i = k-2;i >= 0;i--)pre = (pre+a[i]-1)/a[i]*a[i];
  if(pre == 1){
    cout << 2 << " " << 2 << endl;
    return 0;
  }
  {
    ll l = pre;
    rep(i,k)l = l/a[i]*a[i];
    if(l != 2){
      cout << -1 << endl;
      return 0;
    }
  }
  ll left = pre,right = 1ll << 60;
  while(right-left > 1){
    ll mid = (right+left)/2;
    ll l = mid;
    rep(i,k)l = l/a[i]*a[i];
    if(l == 2)left = mid;
    else right = mid;
  }
  cout << pre << " " << right-1 << endl;
  






  return 0;
}
