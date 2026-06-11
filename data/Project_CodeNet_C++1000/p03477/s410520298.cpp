#include <bits/stdc++.h>
using namespace std;

int main() {
  int A;
  int B;
  int C;
  int D;
  
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> D;
  
  if((A+B) == (C+D)){
  cout << "Balanced" << endl;
  }else if((A+B) < (C+D)){
    cout << "Right" << endl;
  }else{
    cout << "Left" << endl;
  }
}
