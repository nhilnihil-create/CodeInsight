#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int AB = A * B;
  
  if (AB % 2 == 0){
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
  return 0;

}