#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D,p,q;
  
  cin >> A >> B >> C >> D;
  
  p=A+B;
  q=C+D;
  
  if (p>q) {
    cout << "Left" << endl;
    }
  else if (q>p){
    cout << "Right" << endl;
    }
  else {
    cout << "Balanced" <<endl;
   }
  
}
