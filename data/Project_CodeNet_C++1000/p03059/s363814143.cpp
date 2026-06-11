#include<iostream>
using namespace std;

int main(){
  int a, b, t;
  cin >> a >> b >> t;
  int ans = 0;
  for(int i = a; i <= t; i += a) ans += b;
  cout << ans << endl;
  return 0;
}
