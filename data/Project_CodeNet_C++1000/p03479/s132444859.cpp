#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t x,y;
	cin >> x >> y;

	int64_t m=y/x;
	int maxbit=0;

	for (int i=0;i<63;++i)
	{
		if ((m&1)!=0)
		{
			maxbit=i;
		}
		m>>=1;
	}
	cout << maxbit+1 << endl;
}





