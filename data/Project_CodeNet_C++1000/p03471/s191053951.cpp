#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  ll n,y;
  cin >> n >> y;
  if(10000*n<y){
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
  }
  ll ten=min(n,y/10000);
  for(ll i=0;i<ten+1;i++){
    ll five=min(n-i,y/5000);
    for(ll j=five;j>=0;j--){
      if(10000*i+5000*j+1000*(n-i-j)==y){
        cout << i << " " << j << " " << n-i-j << endl;
        return 0;
      }
      else if(10000*i+5000*j+1000*(n-i-j)<y)
      break;
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
}