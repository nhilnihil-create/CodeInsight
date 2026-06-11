#include<bits/stdc++.h>
using namespace std;
long long n,a,b,MIN,sum,bo;
int main()
{
	cin>>n;
	MIN=2000000000;
	while(n--)
	{
		cin>>a>>b;
		if(a>b)MIN=min(MIN,b);
		if(a!=b)bo=1;
		sum+=b;
	}
	if(bo)cout<<sum-MIN;
	  else cout<<0;
	return 0;
}