#include <bits/stdc++.h>
using namespace std;

int main() {
	long long x,y,z=0;
	cin >> x >> y;
	if(x % y == 0)
	{
		z = -1;
	}
	else
	{
		z = (x * y) - x;
	}
	cout << z <<endl;
	return 0;
}
