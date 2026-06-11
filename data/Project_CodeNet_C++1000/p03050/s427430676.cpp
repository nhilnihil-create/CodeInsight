#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long int res = 0;
	long long int n;

	cin >> n;

	for(long long int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			long long int a = i - 1;
			long long int b = (n/i) - 1;
			if(a==b)
			{
				if(a!=0)
				{
					if((n/a)==n%a)
					{
						res += a;
					}
				}
			}
			else
			{
				if(a!=0)
				{
					if((n/a)==n%a)
					{
						res += a;
					}
				}
				if(b!=0)
				{
					if((n/b)==n%b)
					{
						res += b;
					}
				}
			}
		}
	}

	cout << res << '\n';
	
	return 0;
}