#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	string s;
	unsigned long long int k;
	cin >> s >> k;
	int count = 0;
	for (int i = 0; i < 100; ++i)
	{
		if (s[i] - '0' == 1)
		{
			++count;
		}
		if (s[i] != '1')
		{
			break;
		}
	}
	if (count >= k)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << s[count] << endl;
	}
	return 0;
}