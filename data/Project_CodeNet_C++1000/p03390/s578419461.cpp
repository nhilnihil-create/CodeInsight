#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int q;
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		long long a[2];
		cin>>a[0]>>a[1];
		sort(a,a+2);
		if (a[0]==a[1]||a[0]+1LL==a[1])
		{
			cout<<2LL*(a[0]-1LL)<<endl;
			continue;
		}
		long long ok=0LL,ng=a[1];
		while (ng-ok>1LL)
		{
			long long mid=(ok+ng)/2LL;
			if (mid*mid<a[0]*a[1])
			{
				ok=mid;
			}
			else
			{
				ng=mid;
			}
		}
		if (ok*(ok+1LL)>=a[0]*a[1])
		{
			cout<<2LL*(ok-1LL)<<endl;
		}
		else
		{
			cout<<2LL*ok-1LL<<endl;
		}
	}
	return 0;
}
