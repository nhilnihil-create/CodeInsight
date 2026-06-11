#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	long long int x,y;

	cin >> x >> y;

	if(x%y==0)
	{
		cout << -1 << '\n';
		return 0;
	}

	for(long long int i=1; ;i++)
	{
		long long int val = i*x;
		if(val%y!=0)
		{
			cout << val << '\n';
			return 0;
		}
	}
	return 0;
}