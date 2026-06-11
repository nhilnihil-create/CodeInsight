#include<bits/stdc++.h>
#include <bitset>
using namespace std;

int main()
{
	
	long long int r,c,pro;
	cin>>r>>c;
	int k,l;
	
	pro=0;

	if(r==1)
	{
		if(c==1)
			pro=1;
		else if(c==2)
			pro=0;
		else
		{
			pro=c-2;
		}
	}

	else if(c==1)
	{
		
		if(r==2)
			pro=0;
		else
		{
			pro=r-2;
		}
	}
	else
	{
		pro=(r-2)*(c-2);
	}
	/*
	for(long long int i=1;i<=r;i++)
	{
		for(long long int j=1;j<=c;j++)
		{
			k=l=1;
			if((i-1)>=1)
				k++;
			if((i+1)<=r)
				k++;

			if((j-1)>=1)
				l++;
			if((j+1)<=c)
				l++;
			if((l*k)%2==1)
				pro++;
		}
	}
	*/
	cout<<pro<<"\n";
	return 0;
}
