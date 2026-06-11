#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3],k,pro=1;
	for(int i=1;i<=3;i++)
	{
		cin>>a[i];
	}
	cin>>k;
	sort(a+1,a+3+1);
	for(int j=1;j<=k;j++)
	{
		pro=pro*2;
	}
	cout<<a[3]*pro+a[1]+a[2];
	return 0;
}