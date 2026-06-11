#include <bits/stdc++.h>
using namespace std;

int main(){
  int k;
  cin >> k;
  
  int ans = 0;
  if(k % 2) ans = k/2 * (k+1)/2;
  else ans = k * k /4;
  cout << ans << endl;
}