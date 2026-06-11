#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,a=1;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		if(a<k)
		{
			a=a*2;
		}
		else
		{
			a=a+k;
		}
	}
	cout<<a;
	return 0;
}