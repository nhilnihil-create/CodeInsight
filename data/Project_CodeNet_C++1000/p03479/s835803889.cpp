#include<iostream>
using namespace std;
int main()
{
	long long x, y, ans;
	ans = 0;
	cin >> x >> y;
	for (long long i = 0; x <= y; i++)
	{
		ans++;
		x *= 2;
	}

	cout<<ans;

	return 0;
}