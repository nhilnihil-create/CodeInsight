#include<iostream>
using namespace std;
long a,b,c,n;
main()
{
	cin>>n;
	for(a=1;a<=3500;a++)for(b=a;b<=3500;b++)
	{
		long u=n*a*b,p=4*a*b-n*a-n*b;
		if(p>0&&u%p==0)
		{
			cout<<a<<" "<<b<<" "<<u/p<<endl;
			return 0;
		}
	}
}
