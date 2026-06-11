#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#define ll long long int
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	ll a[n+1],b[n+1],count=0,sum=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
		count++;
		b[i]=abs(a[i]);
		sum=sum+b[i];
	}
	sort(b,b+n);
	if(count%2==0)
	cout<<sum<<endl;
	else
	cout<<sum-b[0]*2<<endl;
	return 0;
 } 