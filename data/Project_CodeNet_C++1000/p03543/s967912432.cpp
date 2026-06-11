#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int N, a, b, c, d;

	cin >> N;
	a = N / 1000;
	b = N % 1000 / 100;
	c = N % 1000 % 100 / 10;
	d = N % 1000 % 100 % 10;
	if ((a == b) && (b == c) || (b == c) && (c == d))
    {
      cout << "Yes" << endl;
    }
	else
    {
      cout << "No" << endl;
    }
  return (0);
}