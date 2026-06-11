#include <bits/stdc++.h>
using namespace std;

const double eps=1e-5;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int a[n],s=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		s+=a[i];
	}
	double ave=(double)s/n,mi=1000000.0,ans=-1;
	for (int i = 0; i < n; ++i)
	{
		if (fabs((double)ave-a[i])+eps<mi)
		{
			mi=fabs((double)ave-a[i]);
			ans=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
