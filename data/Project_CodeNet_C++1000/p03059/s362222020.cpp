#include <bits/stdc++.h>
using namespace std;

int main() {
 int A, B, T;
 cin >> A >> B >> T;
  
  int count = 0;
  
  while (T - A >= 0 ){
   count += B;
   T -= A;
  }
  
  cout << count << endl;
}