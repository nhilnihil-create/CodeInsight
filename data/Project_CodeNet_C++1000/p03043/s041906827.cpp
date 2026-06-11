#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int i,j,n,k,x=0;
	cin>>n>>k;
	double s,z=0,t=0.5,y;
	if(n>=k)
	{
		y=k;
	}
	else
	{
		y=n+1;
	}
	for(i=1;i<y;i++)
	{
		x=0;
		for(j=i;j<k;)
		{
			j=j*2;
			x++;
		}

		s=pow(t,x);
		s=s/n;
		z=z+s;

	}
	
	if(n>=k)
	{
		s=(n-k+1)/(n*1.0);
	
		cout<<fixed<<setprecision(10)<<z+s<<endl;
		return 0;
	}
	cout<<fixed<<setprecision(10)<<z<<endl;
	
}