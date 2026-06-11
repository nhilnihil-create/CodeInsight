#include <bits/stdc++.h>
using namespace std;
int main(){
  int f;
  cin >> f;
  int s = f % 100;
  f /= 100;
  bool fbl = (1 <= f && 12 >= f), sbl = (1 <= s && 12 >= s);
  if(fbl && sbl) cout << "AMBIGUOUS";
  else if(fbl) cout << "MMYY";
  else if(sbl) cout << "YYMM";
  else cout << "NA";
}