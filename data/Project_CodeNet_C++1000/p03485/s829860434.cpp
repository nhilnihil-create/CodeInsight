#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a = 0, b = 0, x = 0;
  cin >> a;
  cin >> b;
  x = a + b;
  
  if(x % 2 == 0){
  	cout << x/2;
  } else {
  	cout << (x/2) + 1;
  }
}