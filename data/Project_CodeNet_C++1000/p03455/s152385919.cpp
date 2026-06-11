#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a = 0;
  int b = 0;
  int ab = 0;
  
  cin >> a >> b;
  
  ab = (a * b)%2;
  
  if (ab == 0){
  cout << "Even" << endl;
  }
  else{
  cout << "Odd" << endl;
  }
}
