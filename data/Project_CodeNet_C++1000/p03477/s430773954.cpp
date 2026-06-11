#include <iostream>
using namespace std;

int main()
{
  int A,B,C,D;
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> D;
  
  if((A+B) > (C+D))
    cout << "Left";
  else if((A+B) == (C+D))
    cout << "Balanced";
  else
    cout << "Right";
}