#include <bits/stdc++.h>
using namespace std;
deque < long long > a;
deque < long long > b;
int main()
{
	int n,a2,b2;
	cin>>n;
	for(long long i=0;i<n;i++)
	{
		cin>>a2;
		a.push_back(a2);
	}
	for(long long i=0;i<n;i++)
	{
		cin>>b2;
		b.push_back(b2);
	}
	long long k=0,k2=0;
	for(long long i=0;i<n;i++)
		k+=b[i]-a[i];
	for(long long i=0;i<n;i++)
		if(b[i]-a[i]>0)
			k2+=(b[i]-a[i]+1)/2;
	if(k2>k)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
}