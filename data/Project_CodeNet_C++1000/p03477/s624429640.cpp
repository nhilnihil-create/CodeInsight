#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int A, B, C, D, L, R;

	cin >> A >> B >> C >> D;
	L = A + B;
	R = C + D;
	if (L > R)
    {
      cout << "Left" << endl;
    }
	else if (L == R)
    {
      cout << "Balanced" << endl;
    }
	else if (L < R)
    {
      cout << "Right" << endl;
    }
  return (0);
}