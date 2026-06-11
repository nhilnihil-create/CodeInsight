#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	int c[n-1];
	int s[n-1];
	int f[n-1];
	for(int i=0;i<n-1;i++)
		cin>>c[i]>>s[i]>>f[i];
	
		int res[n];
	for(int i=0;i<n-1;i++)
	{
		int t=0;
		for(int j=i;j<n-1;j++)
		if(t<=s[j])
		{
			t=s[j]+c[j];
		}
		else
		{
			int r = (f[j] - t%f[j])%f[j];
			t += r + c[j];
			
			
		}
		res[i]=t;
	}
	res[n-1]=0;
	for(int i=0;i<n;i++)
	{
		cout<<res[i]<<"\n";
	}

}