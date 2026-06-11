#include <bits/stdc++.h>
using namespace std;

int main() {
   
  int n;
  cin >> n;
  int x = n;
  
  int sum = 0;
  for (int i = 0; i < 9; i++){
     sum += x % 10;
     x /= 10;
   }
  
  if (n % sum == 0){
   cout << "Yes" << endl;
  }
  else {
   cout << "No" << endl;
  }
}

