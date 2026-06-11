#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n, maxv = -114514191, minv = 9810114514;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		int x;
		cin >> x;
		maxv = max(maxv, x);
		minv = min(minv, x);
	}
	cout << abs(maxv - minv);
	return 0;
}