#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1<<17],m,d;
main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>m)m=a[i];
	}
	d=-1;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=m)
		{
			if(abs(m-2*a[i])<abs(m-2*d))d=a[i];
		}
	}
	cout<<m<<endl<<d<<endl;
}
