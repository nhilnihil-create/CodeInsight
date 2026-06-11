#include<iostream>
#include<algorithm>
using namespace std;
int n;
long X,x[2<<17];
long ans=9e18;
long calc(int k)
{
	long now=(n+k)*X;
	for(int i=0;i<n;i++)
	{
		now+=x[n-i-1]*(i/k==0?5:i/k*2+3);
	}
	return now;
}
main()
{
	cin>>n>>X;
	for(int i=0;i<n;i++)cin>>x[i];
	int L=1,R=n+1;
	ans=min(calc(1),calc(n));
	while(R-L>2)
	{
		int k1=(L*2+R)/3;
		int k2=(L+R*2)/3;
		long now1=calc(k1);
		long now2=calc(k2);
		ans=min(ans,min(now1,now2));
		if(now1<now2)R=k2;
		else L=k1;
	}
	cout<<ans<<endl;
}