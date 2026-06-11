#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

long long int ans = 0;
int n, k;

void solve(){
  cin >> n >> k;
  if(k % 2 == 1){
    ans = pow(n / k, 3);
  }
  else{
    int a = 0, b = 0;
    for(int i = 1; i <= n; i++){
      if(i % k == 0) a++;
      else if(i % k == k / 2) b++;
    }
    ans = pow(a, 3) + pow(b, 3);
  }
  cout << ans << endl;
  return;
}
int main(){
  solve();
  return 0;
}
