#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int ans = b;
  if(a <= 5) ans *= 0;
  else if(a >= 6 && a <= 12) ans *= 0.5;
  else ans *= 1;
  cout << ans << endl;
  return 0;
}