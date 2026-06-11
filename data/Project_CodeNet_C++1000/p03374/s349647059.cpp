#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long 
ll n,c,a[100010],b[100010],ans1[100010],ans2[100010],ans3[100010],ans4[100010],anss1,anss2,anss3,anss4;
int main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
	}
	ll sum=0;
	anss1=anss2=anss3=anss4=0;
	for(int i=1;i<=n;i++)
	{
		sum+=b[i];
		ll tt=sum-a[i];
		ans1[i]=max(ans1[i-1],tt);
		ll tmp=sum-2*a[i];
		ans2[i]=max(tmp,ans2[i-1]);
		anss1=max(ans1[i],anss1);
	//	anss2=max(ans2[i],anss2);
	//	cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	sum=0;
	for(int i=n;i>=1;i--){
		sum+=b[i];
		ll tt=sum-c+a[i];
		ans3[i]=max(ans3[i-1],tt);
		ll tmp=sum-2*c+2*a[i];
		ans4[i]=max(tmp,ans4[i-1]);
		anss3=max(ans3[i],anss3);
	//	anss4=max(ans4[i],anss4);
	//	cout<<ans3[i]<<" "<<ans4[i]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		anss2=max(anss2,ans1[i]+ans4[i+1]);
	}
	for(int i=1;i<=n;i++)
	{
		anss4=max(anss4,ans2[i]+ans3[i+1]);
	}
	ll ans=0;
	ans=max(anss1,anss2);
	ans=max(ans,max(anss3,anss4));
	cout<<ans;
	return 0;
}