#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, k;
	cin >> a >> b >> k;
	map<int, int> M;
	for (int i = 0; i < k; ++i)
	{
		if (a + i <= b)
		{
			cout << a + i << endl;
			M[a+i] = 1;
		}
	}
	for (int i = k-1; i >= 0; --i)
	{
		if (!M[b-i] && b - i >= a)
		{
			cout << b - i << endl;
		}
	}
	return 0;
}