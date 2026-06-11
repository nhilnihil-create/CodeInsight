#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

void solve(){
  ll n, m, ans = 1; cin >> n >> m;
  for(ll i = 1; i <= sqrt(m) + 2; i++){
    if(m % i == 0){
      if(m / i >= n) ans = max(ans, i);
      if(i >= n) ans = max(ans, m / i);
    }
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
