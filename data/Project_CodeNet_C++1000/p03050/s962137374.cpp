#include<bits/stdc++.h>
using namespace std;
long long arr[1000000];
int main()
{
	long long n,i,j,k,ans;
	ans=0;
	cin>>n;
	for (i=1;i*i<=n;i++)
	{
		j=n-i;
		if (i*i==n)
		{
			break;
		}
		if (j%i==0)
		{
			if (n%(j/i)==0)
			{
				break;
			}
			ans=ans+j/i;	
		}
	}
	cout<<ans<<endl;
}