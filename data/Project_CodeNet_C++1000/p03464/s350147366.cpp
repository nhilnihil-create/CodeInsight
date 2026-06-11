#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	reverse(a,a+n);
	long long l=2LL,r=3LL;
	for (int i = 0; i < n; ++i)
	{
		l=(l+a[i]-1LL)/a[i]*a[i];
		r=(r-1LL)/a[i]*a[i]+a[i];
		if (r<=l)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<l<<" "<<r-1LL<<endl;
	return 0;
}
