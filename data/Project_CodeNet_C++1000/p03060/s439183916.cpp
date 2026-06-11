#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1],b[n+1];
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];
	int s=0; 
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[i])
		s+=a[i]-b[i];
	}
	cout<<s;
	return 0;
 } 