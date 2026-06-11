#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  
  int x = 0;
  x = A / 500;
  if (x * 500 + B >= A){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}