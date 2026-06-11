#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
	int n,j=0;
	long long sum=0,xorsum=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{   
	    while(j+1<=n&&(xorsum^a[j+1])==sum+a[j+1])
	    {
		    sum=sum+a[j+1];
		    xorsum=xorsum^a[j+1];
		    j++;
	    }
	    s=s+j-i+1;
		sum=sum-a[i];	
		xorsum=xorsum^a[i];	
	}
	cout<<s;
}