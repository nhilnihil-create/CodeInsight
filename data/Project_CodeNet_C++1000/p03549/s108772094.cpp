#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  ll n, m;
  cin >> n >> m;
  ll ans = (m*1800+n*100);
  for(int i=0; i<m; i++){
    ans *= 2LL;
  }
  cout << ans << endl;
  return 0;
}
