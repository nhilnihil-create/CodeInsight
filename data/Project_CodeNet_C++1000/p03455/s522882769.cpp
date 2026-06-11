#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int a, b, product;

	cin >> a >> b;
	product = a * b;
	if (product % 2 == 0)
    {
      cout << "Even" << endl;
    }
	else if (product % 2 == 1)
    {
      cout << "Odd" << endl;
    }
	return (0);
}