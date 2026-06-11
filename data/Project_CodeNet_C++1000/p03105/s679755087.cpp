#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n-1; i >= 0; i--)
using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int ans = min(b/a, c);
  cout << ans << endl;
  
  return 0;
}