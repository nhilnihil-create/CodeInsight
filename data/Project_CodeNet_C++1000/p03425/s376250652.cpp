#include<iostream>
using namespace std;
long long n,sum1,sum2,sum3,sum4,sum5,ans;
char a[100006][200];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]=='M')sum1++;
		if(a[i][0]=='A')sum2++;
		if(a[i][0]=='R')sum3++;
		if(a[i][0]=='C')sum4++;
		if(a[i][0]=='H')sum5++;
	}
	ans+=sum1*sum2*sum3;
	ans+=sum1*sum2*sum4;
	ans+=sum1*sum2*sum5;
	ans+=sum1*sum3*sum4;
	ans+=sum1*sum3*sum5;
	ans+=sum1*sum4*sum5;
	ans+=sum2*sum3*sum4;
	ans+=sum2*sum3*sum5;
	ans+=sum2*sum4*sum5;
	ans+=sum3*sum4*sum5;
	cout<<ans<<endl;
	return 0;
}