#include <bits/stdc++.h>
using namespace std;

int main(){

  int A, B;
  cin >> A >> B;
    
  int x1, x2;
  x1 = max(A, B);
  x2 = max(max(A, B)-1, min(A, B));
  
  cout << x1+x2 << endl;
 
}