#include<iostream>
using namespace std;
main()
{
	int q;cin>>q;
	for(;q--;)
	{
		long a,b;cin>>a>>b;
		if(a>b)a^=b^=a^=b;
		if(a==b||a+1==b)
		{
			cout<<2*a-2<<endl;
		}
		else
		{
			long f=0,l=1e9;
			for(int i=0;i<99;i++)
			{
				long m=(f+l)/2;
				if(m*m<a*b)f=m;
				else l=m;
			}
			if(f*(f+1)>=a*b)
			{
				cout<<2*f-2<<endl;
			}
			else
			{
				cout<<2*f-1<<endl;
			}
		}
	}
}