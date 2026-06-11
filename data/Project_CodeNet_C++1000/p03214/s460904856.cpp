#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
using namespace std;
int main()
{
	double m=100,n,s=0,a[114];
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],s+=a[i];
	s=s/n;
	int p;
	for(int i=0;i<n;i++)
	{
		if(abs(s-a[(int)n-1-i])<=m)
		{
			p=n-1-i;
			m=abs(s-a[(int)n-1-i]);
		}
	}
	cout<<p<<endl;
}