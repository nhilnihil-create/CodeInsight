#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n;
  ll h;
  cin >> n >> h;
  ll a[n], b[n];
  ll ma = 0;
  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i];
    ma = max(a[i], ma);
  }
  sort(b, b+n, greater<int>());
  ll ans = 0;
  for(int i=0; i<n; i++){
    if(b[i]>ma){
      ans++;
      h -= b[i];
    }
    if(h<=0){
      cout << ans << endl;
      return 0;
    }
  }
  ans += h/ma;
  if(h%ma!=0) ans++;
  cout << ans << endl;
  return 0;
}
