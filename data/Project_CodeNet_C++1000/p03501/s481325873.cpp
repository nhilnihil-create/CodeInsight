#include <iostream>
using namespace std;

int main()
{
  int N,A,B;
  cin >> N;
  cin >> A;
  cin >> B;
  
  if((A*N) >= B)
    cout << B;
  else
    cout << A*N;
}