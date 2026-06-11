#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long a,b;
	int k;
	cin>>a>>b>>k;
	for (int i = 0; i < k; ++i)
	{
		if (i%2==0)
		{
			a-=a%2LL;
			b+=a/2LL;
			a/=2LL;
		}
		else
		{
			b-=b%2LL;
			a+=b/2LL;
			b/=2LL;
		}
	}
	cout<<a<<" "<<b<<endl;
	return 0;
}
