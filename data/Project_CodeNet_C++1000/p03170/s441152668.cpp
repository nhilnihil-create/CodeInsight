#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	int i,j;
	for(i=0;i<n;i++)
	cin>>a[i];
	bool b[k+1];
	memset(b,false,sizeof(b));
	for(i=1;i<=k;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i-a[j]>=0)
			{
				if(b[i-a[j]]==false)
				{
					b[i]=true;
					break;
				}
			}
		}
	}
	if(b[k]==true)
	cout<<"First";
	else
	cout<<"Second";
}