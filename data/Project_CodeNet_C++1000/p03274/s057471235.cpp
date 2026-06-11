#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  bool f = true;
  int p = n-1;
  for(int i=0; i<n; ++i){
    cin >> c[i];
    if(f && c[i] >=0){
      f = false;
      p = i;
    }
  }
  ll x = min(p+k-1, n-1);
  ll plus = max(0,c[x]), minus = - min(0,c[x-k+1]);
  ll ans = min(plus *2 +minus, minus *2 +plus);
  //cout << "m:" << minus << " p:" << plus << " ans:" << ans << endl;
  for(int i=x; i>=p && i-k>=0; --i){
    plus -= c[i] - max(0, c[i-1]);
    minus -= c[i-k] -min(0, c[i-k+1]);
    ll tot = min(plus *2 +minus, minus *2 +plus);
    //cout << "m:" << minus << " p:" << plus << " tot:" << tot << endl;
    ans = min(ans, tot);
  }
  cout << ans << endl;
}