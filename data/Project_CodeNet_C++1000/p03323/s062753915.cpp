#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A , B;
  cin >> A >> B;
  A = max(A,B);
  if (A > 8){
    cout << ":(" << endl;
  }
  else{
    cout << "Yay!" << endl;
  }
}