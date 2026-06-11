#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int AB, BC, CA;
  cin >> AB >> BC >> CA;
  
  cout << AB*BC*CA/max(max(AB,BC),CA)/2 << endl;

return 0;
}