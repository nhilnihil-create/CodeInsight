#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(ll i = 0;i*i<=n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  ll n;
  cin >> n;
  ll ans = 0;;
  rep(i,n){
    if(i * i <= n){
      ans = max(ans,i*i);
    }
    else break;
  }
  cout << ans << endl;
  return 0;
}
