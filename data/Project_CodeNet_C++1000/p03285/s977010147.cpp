#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int ans = 0, n;
	cin >> n;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (i * 4 + j * 7 == n)
			{
				++ans;
			}
		}
	}
	cout << ((ans == 0)?"No":"Yes") << endl;
	return 0;
}