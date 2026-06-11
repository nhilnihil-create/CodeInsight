#include <iostream>
using namespace std;

int main()
{
    int A,B,C;
  cin >> A >> B >> C;
  if(A==B && A!=C){cout << C;}
  else if (A==C && A!=B){cout << B;}
  else {cout << A;}
    return 0;
}
