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
	int n; cin >> n; int a[2000];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (!(i % 2))
			sum1 += a[i];
		else
			sum2 += a[i];
	}
	cout << abs(sum2 - sum1);
}