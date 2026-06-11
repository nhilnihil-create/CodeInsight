#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	int s;
	cin >> s;
	if (s == 1)
	{
		s += 3;
	}
	else if (s == 2)
	{
		s += 2;
	}
	int i = s;
	int cnt = 1;
	while (i > 1)
	{
		if (i % 2 == 0)
			i /= 2;
		else 
			i = (i*3)+1;
		cnt++;
	}
	cout << cnt+1 << endl;
	return (0);
}
