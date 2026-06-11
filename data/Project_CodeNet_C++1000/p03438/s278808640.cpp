//Why it is WA?It should be AC.
#include<bits/stdc++.h>
long long a[10000],b[10000];
using namespace std;
int main()
{
	long long n,i=0,j=0,k,ba=0;
	cin>>n;
	for(int t=0;t<n;t++)
	{
		cin>>a[t];
		i=i+a[t];
	}
	//cout<<i<<" ";
	for(int t=0;t<n;t++)
	{
		cin>>b[t];
		j=j+b[t];
	}
	//cout<<j<<endl;
	if(i<=j)
	{
		k=j-i;
		//cout<<k<<" ";
		for(int t=0;t<n;t++)
		{
			if(a[t]<b[t])
			{
				ba=ba+(b[t]-a[t]+1)/2;
				//cout<<(b[t]-a[t]+1)/2<<" "; 
			} 
		}
		//cout<<ba<<" ";
		if(ba>k)
		{
			cout<<"No";
		}
		else
		{
			cout<<"Yes";
		}
	}
	else
	{
		cout<<"No";
	}
	return 0;
} 