#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a,b,c,k;
  cin >> a >> b >> c >> k;
  int ans=a-b;
  if(k%2==0) cout << ans <<endl;
  else cout << -ans << endl;
  return 0;
}
