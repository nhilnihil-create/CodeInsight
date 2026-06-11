#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void solve(){
  int a[3]; cin >> a[0] >> a[1] >> a[2];
  int maxi = 0;
  for(int i = 1; i < 3; i++){
    if(a[i] > a[maxi]) maxi = i;
  }
  int ans = 10 * a[maxi];
  for(int i = 0; i < 3; i++){
    if(i == maxi) continue;
    ans += a[i];
  }
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
