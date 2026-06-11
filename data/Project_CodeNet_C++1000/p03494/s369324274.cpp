#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n;
	cin>>n;
	long int x=0,i,a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];		
	}

	
	
for(int j=0;;j++)
{
	
	
	for(i=0;i<n;i++)
	{

		if(a[i]%2!=0)
		{
			cout<<x<<endl;
			return 0;
		}
		a[i]=a[i]/2;
	}
	x++;

}
}
