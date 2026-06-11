#include <bits/stdc++.h>
using namespace std;

int main() {
  int intA, intB, intC, intD;
  cin >> intA >> intB >> intC >> intD;

  if ((intA + intB) > (intC + intD)) {
    cout << "Left" << endl;
  }
  else if ((intA + intB) == (intC + intD)) {
    cout << "Balanced" << endl;
  }
  else{
    cout << "Right" << endl;
  }    

}
