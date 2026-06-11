#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin >> a >> b;
  int modu_a = a%2;
  int modu_b = b%2;
  if (modu_a * modu_b == 0){
   cout << "Even" << endl; 
  }
  else {
   cout << "Odd" << endl; 
  }
}