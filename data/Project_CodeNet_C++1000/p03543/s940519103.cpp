#include <bits/stdc++.h>
using namespace std;

int main() {
  int intN;
  cin >> intN;

  int int1000, int100, int10, int1;
  
  int1000 = intN / 1000;
  int100 = (intN % 1000) / 100;
  int10 = (intN % 100) / 10;
  int1 = intN % 10;
  
  if (int100 == int10){
    if (int1000 == int100){
	    cout << "Yes" << endl;
    }
    else if (int10 == int1){
	    cout << "Yes" << endl;
    }
    else{
	    cout << "No" << endl;
    }
    
  }
  else{
    cout << "No" << endl;
  }
  
}
  
 