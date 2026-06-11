#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
int n,t[111],v[111],v2[111];
main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>t[i],t[i]*=2;
	for(int i=0;i<n;i++)cin>>v[i],v[i]*=2;
	for(int j=n;j--;)v2[j]=min({v[j],v[j+1],v2[j+1]+t[j+1]});
	int now=0;
	long ans=0;
	for(int i=0;i<n;i++)
	{
		//cout<<now<<" "<<v[i]<<" "<<v2[i]<<endl;
		int left=v[i]-now;
		int right=v[i]-v2[i];
		//cout<<left<<" "<<right<<endl;
		if(left+right<=t[i])
		{
			ans+=v[i]*t[i]-right*right/2-left*left/2;
		}
		else if(t[i]<left&&now+t[i]<=v2[i])
		{
			ans+=t[i]*t[i]/2+now*t[i];
		}
		else
		{
			int x=(v2[i]+t[i]-now)/2;
			//now+x==v2[i]+(t[i]-x)<=>2*x==v2[i]+t[i]-now
			long get=(x*x+(t[i]-x)*(t[i]-x))/2;
			long Min=min(now,v2[i]);
			get+=(now-Min)*x+(v2[i]-Min)*(t[i]-x);
			ans+=get+Min*t[i];
		}
		//cout<<ans<<endl<<endl;
		now=min(now+t[i],v2[i]);
	}
	cout<<fixed<<setprecision(15)<<(double)ans/4<<endl;
}
