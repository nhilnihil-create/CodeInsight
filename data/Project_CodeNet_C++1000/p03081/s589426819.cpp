#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,q;
	string s;
	cin>>n>>q>>s;
	char t[q],d[q];
	for (int i = 0; i < q; ++i)
	{
		cin>>t[i]>>d[i];
	}
	int lng=-1,lok=n;
	while(abs(lok-lng)>1)
	{
		int mid=(lng+lok)/2,now=mid,f=1;
		for (int i = 0; i < q; ++i)
		{
			if (s.at(now)==t[i])
			{
				if (d[i]=='L')
				{
					--now;
				}
				else
				{
					++now;
				}
				if (now<0)
				{
					f=0;
					break;
				}
				if (now>n-1)
				{
					break;
				}
			}
		}
		if (f==1)
		{
			lok=mid;
		}
		else
		{
			lng=mid;
		}
	}
	int rng=n,rok=-1;
	while(abs(rok-rng)>1)
	{
		int mid=(rng+rok)/2,now=mid,f=1;
		for (int i = 0; i < q; ++i)
		{
			if (s.at(now)==t[i])
			{
				if (d[i]=='L')
				{
					--now;
				}
				else
				{
					++now;
				}
				if (now>n-1)
				{
					f=0;
					break;
				}
				if (now<0)
				{
					break;
				}
			}
		}
		if (f==1)
		{
			rok=mid;
		}
		else
		{
			rng=mid;
		}
	}
	cout<<rok-lok+1<<endl;
	return 0;
}
