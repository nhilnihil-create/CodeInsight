#include <iostream>
#include <cstdio>
#include <string>
#define int long long
using namespace std;

int k;

double S(int x)
{
	string s = to_string(x);
	int res = 0;
	for (int i=0; i<(int) s.size(); i++)
		res+=(s[i]-'0');
	return (double) res / x;
}

main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin >> k;
	int cnt = 10;
	int step = 10;
	for (int i=1; i<=k; i++)
	{
		if (i<=9)
			cout << i << '\n';
		else
		{
			cnt+=step;
			cout << cnt-1 << '\n';
			if (S(cnt+step-1)<S(cnt+step*10-1))
				step*=10;
		}
	}
	
	
	return 0;
}
