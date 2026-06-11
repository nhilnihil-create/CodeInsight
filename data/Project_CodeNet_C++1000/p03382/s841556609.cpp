#include<bits/stdc++.h>
using namespace std;
int n;
long long a[101111];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	int ans=1e9+10;
	long long res;
	for(int i=1;i<n;i++)
	{
		if(abs(a[i]-(a[0]-a[i]))<ans)
		{
			ans=abs(a[i]-(a[0]-a[i]));
			res=a[i];
		}
	}
	cout<<a[0]<<' '<<res<<endl;
	return 0;
}