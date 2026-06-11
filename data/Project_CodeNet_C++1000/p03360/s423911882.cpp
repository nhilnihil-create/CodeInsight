#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	int s = a+b+c;
	int m = max(max(a, b), c);
	int t = s - m;
	while(k > 0)
	{
		k -= 1;
		m = 2*m;
	}
	cout << t + m;
}