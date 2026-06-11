#include <iostream>
#include <string>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans = 0;
  int x = 0;
  rep(i, n){
    int p;
    cin >> p;
    ans += p;
    x = max(x, p);
  }
  ans -= x/2;
  cout << ans << endl;
  
  return 0;
}