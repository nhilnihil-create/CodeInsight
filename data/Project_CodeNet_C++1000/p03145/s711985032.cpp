#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;


int main(){
  int AB, BC, CA;
  cin >> AB >> BC >> CA;
  if (AB < CA && BC < CA) cout << AB * BC / 2 << endl;
  else if (BC < AB && CA < AB) cout << BC * CA / 2 << endl;
  else cout << CA * AB / 2 << endl;
}