#include <bits/stdc++.h>
using namespace std;

int main(){
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;
  
  int m = max({a1, a2, a3});
  int s = min({a1, a2, a3});
  
  int ans = m - s;
  cout << ans << endl;
}
  
  
