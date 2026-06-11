#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int input1, input2;
  cin >> input1 >> input2;

  if((input1 /2)*2 == input1 || (input2 /2)*2 == input2) {
    cout << "Even" << endl;
  } else {
    cout << "Odd" << endl;
  }
  
  return 0;
}