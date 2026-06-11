#include <bits/stdc++.h>
using namespace std;

int main() {
  int intN, intA, intB;
  cin >> intN >> intA >> intB;

  if ((intN * intA) < intB) {
    cout << intN * intA << endl;
  }
  else if ((intN * intA) > intB)  {
    cout << intB << endl;
  }
  else{
    cout << intB << endl;
  }    

}
