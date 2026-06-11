#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> an(n);
  for(int i=0; i<n; ++i) cin >> an[i];
  if(an[0]){
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  for(int i=1; i<n; ++i){
    if(an[i] > an[i-1] +1){
      cout << -1 << endl;
      return 0;
    }
    else if(an[i] == an[i-1] +1) ++ans;
    else{
      ans += an[i];
    }
  }
  cout << ans << endl;
}