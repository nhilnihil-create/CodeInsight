#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main(){
  int n, k; cin >> n >> k;
  vector< int > v(n);
  bool pos = false;
  bool neg = false;
  int id = (int)1e9;
  ll ans = (ll)id;
  for(int i = 0; i < n; ++i){
    cin >> v[i];
    if(v[i] < 0)neg = true;
    if(v[i] > 0){
     pos = true;
     id = min(id,i);
    }
    if(v[i] == 0);
  }
  if(!pos) ans = abs(v[n - k]);
  else if(!neg) ans = abs(v[k - 1]);
  else{
    
      for(int i = 0; i < n && i + k - 1 < n;++i){
         ll temp = (ll)abs(v[i]) + (ll)(2*abs(v[i + k -1]));
         ans = min(ans,temp);
      }
      for(int i = n - 1; i >= 0 && i - k + 1 > -1; --i){
          ll temp = (ll)abs(v[i]) + (ll)(2*abs(v[i - k + 1]));
          ans = min(ans,temp);
      }
  }
  cout << ans << '\n';
}