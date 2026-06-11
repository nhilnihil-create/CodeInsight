#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n,m;
	cin>>n>>m;
	long int i,j,k[n],s=0,a[m+1]={0};
	for(i=0;i<n;i++)
	{
		
		cin>>k[i];
		long int x,y,b[k[i]];
		for(j=0;j<k[i];j++)
		{
		cin>>b[j];
		x=b[j];
		a[x]++;
		}
	}
	for(i=0;i<m+1;i++)
	{
	if(a[i]==n)
	{
		s++;
	}
	}
	cout<<s<<endl;
	
}