#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long a,b,ans=0LL,mi=1000000000000000LL;
	int f=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		if (a>b)
		{
			ans+=a;
			mi=min(mi,b);
			f=1;
		}
		else if (a<b)
		{
			ans+=a;
			f=1;
		}
		else
		{
			ans+=a;
		}
	}
	if (f)
	{
		cout<<ans-mi<<endl;
	}
	else
	{
		cout<<"0\n";
	}
	return 0;
}
