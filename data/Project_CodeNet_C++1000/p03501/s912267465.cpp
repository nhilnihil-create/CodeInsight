#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int N, A, B, charge;

	cin >> N >> A >> B;
	charge = N * A;
	if (charge < B)
    {
      cout << charge << endl;
    }
	else
    {
      cout << B << endl;
    }
  return (0);
}