#include<iostream>
using namespace std;
int n,a[100042],x,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(x>n)
			ans++;
		else
			a[x]++;
	}
	for(int i=1;i<=n;i++)
	 if (a[i])
		if(a[i]<i)
			ans+=a[i];
		else if(a[i]>i)
			ans+=a[i]-i;
	cout<<ans;
	return 0;
}