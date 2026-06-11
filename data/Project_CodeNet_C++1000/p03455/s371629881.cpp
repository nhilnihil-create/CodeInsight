#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a, b, x;
  cin >> a >> b;
  
  x = a * b;
    
  if (x % 2 == 0){
    cout << "Even" << endl;
  }
    else if (x % 2 > 0) {
    cout << "Odd" << endl;
  }
}