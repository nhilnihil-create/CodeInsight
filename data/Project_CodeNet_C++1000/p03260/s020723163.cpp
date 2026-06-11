#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >>A>>B;
  
  if(A*B == 1 || A*B == 3 || A*B == 9)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
