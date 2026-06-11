#include <iostream>
using namespace std;

int main()
{
 	int A;
  	int B;
  	int C;
  	cin >> A;
  	cin >> B;
  	cin >> C;
  	if(A == B)
      cout << C;
  	else if(B == C)
      cout << A;
  	else
      cout << B;
}