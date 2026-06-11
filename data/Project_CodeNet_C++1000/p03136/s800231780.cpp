#include <iostream>
using namespace std;
int main()
{
	int n;
	int i = 0;
	int b, c;
	int a[10];
	int sum = 0;
	cin >> n;
	while (n >= 3 && n <= 10)
	{
		while (i <= n-1)
		{
			cin >> a[i];
			i++;
		}
		b = c = 0;
		while (c <= n - 1)
		{
			if (a[b] < a[c])
			{
				b = c;
			}
			c++;
		}
		c = 0;
		while (c <= n - 1)
		{
			if(c!=b)
			   sum = sum + a[c];
			c++;
		}
		
		break;
	}
	if (sum > a[b])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}