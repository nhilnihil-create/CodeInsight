#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, k;
	cin >> n >> k;
	unsigned long long int are = 0;
	unsigned long long int sore = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i % k == 0)
		{
			++are;
		}
		if(k % 2 == 0 && i % k == k / 2)
		{
			++sore;
		}
	}
	cout << (unsigned long long int)(sore*sore*sore + are*are*are) << endl;
	return 0;
}