#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int x;
  cin >> x;
  ll ans = 0;
  for(int i = 1; i <= 32; i++){
    for(int j = 2; j <= 10; j++){
      ll s = pow(i,j);
      if(s <= x) ans = max(ans,s);
    }
  }
  cout << ans << endl;
}