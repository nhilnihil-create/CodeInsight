#include <bits/stdc++.h>
using namespace std;

int main () {
  int D;
  cin >> D;
  
  if (D == 25) cout << "Christmas" << endl;
  else {
    cout << "Christmas";
    for (int i = 0; i < 25-D; i++){
      if (i == 24-D) cout << " Eve" << endl;
      else cout << " Eve";
    }
  }
}