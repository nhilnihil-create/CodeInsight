#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
using namespace std;

int main(){
  int a, b, k;
  cin >> a >> b >> k;
  int ans;
  int n = min(a, b);
  repr(i, n+1){
    if (a % i == 0 && b % i == 0) k--;
    if (k == 0){
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  
  return 0;
}