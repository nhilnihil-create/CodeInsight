#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int a, b, c;
	cin >> a >> b;
  	c = (a + b) / 2;
	if ((a + b) % 2 != 0)
      c += 1;
	cout << c << endl;
}