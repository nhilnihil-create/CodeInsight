#include<bits/stdc++.h>
using namespace std;

int main(void){
  char A, B;
  cin >> A >> B;
  int _A = (int)A - 55;
  int _B = (int)B - 55;
  if(_A == _B)
    cout << "=" << "\n";
  else if(_A < _B)
    cout << "<" << "\n";
  else
    cout << ">" << "\n";
  return 0;
}
