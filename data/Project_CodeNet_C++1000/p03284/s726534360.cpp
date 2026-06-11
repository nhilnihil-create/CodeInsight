#include <iostream>
using namespace std;
int main()
{
	int n, k, div, remainder, a;
	cin >> n >> k;
	div = n / k;
	remainder = n % k;
	a = (div + remainder) - div;
	if (k > n) a = 1;
	if (remainder > div || remainder == div) a = 1;
	cout << a;
	return 0;
}