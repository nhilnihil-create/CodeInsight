#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
	long long r=max(abs(a),abs(b));
	long long l=min(abs(a),abs(b));
	if (l==0LL)
	{
		return r;
	}
	return gcd(l,r%l);
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	long long a,b,c,d;
	for (int i = 0; i < t; ++i)
	{
		cin>>a>>b>>c>>d;
		if (a<b||d<b)
		{
			cout<<"No\n";
			continue;
		}
		if (c>=b-1)
		{
			cout<<"Yes\n";
			continue;
		}
		if (b-gcd(b,d)+a%gcd(b,d)<=c)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	return 0;
}
