#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
	int a, b;
	cin >> a >> b;
	for (int c = 1; c <= 3; ++c)
	{
		if ((a*b*c) % 2 != 0)
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}