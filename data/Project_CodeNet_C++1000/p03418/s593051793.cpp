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
  ll n, k, ans = 0; cin >> n >> k;
  for(int i = 1; i <= n; i++){
    if(i <= k) continue;
    ans += (i - k) * (n / i);
    if(n % i != 0){
      if(n % i + 1 > k){
        ans += (n % i + 1) - k;
        if(k == 0) ans--;
      }
    }
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
