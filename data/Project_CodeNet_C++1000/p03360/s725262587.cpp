#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>

using namespace std;
bool issqr(int n)
{
	double x = sqrt(n);
	double y = floor(x);
	if (x == y)
		return true;
	else
		return false;
}
int main()
{
	int a[3], t;
	cin >> a[0] >> a[1] >> a[2] >> t;
	sort(a, a + 3);
	for (int i = 0; i < t; ++i)
	{
		a[2] *= 2;
	}
	cout << a[2]+ a[0] + a[1];
	
}