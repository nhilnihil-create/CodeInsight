#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x,y;
  cin >> x >> y;
  if(y == 1 || x%y == 0) cout << -1 << endl;
  else{
    if(y == 1000000000) cout << x*(y-1) << endl;
    else cout << x*(y+1) << endl;
  }
}
